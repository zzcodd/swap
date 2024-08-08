#include "subway_app.h"
#include <iostream>
#include <linux/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#define _SVID_SOURCE
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <opencv2/opencv.hpp>
#include <atomic>
#include "src/utils/vpsystem.h"
#include "../config.h"
#include "common_utils/include/file_util.h"
#include "common_utils/include/string_util.h"
#include "common_utils/include/common.h"
#include "src/utils/disk.h"
#include "src/utils/utils.h"
#include "src/utils/log.h"
#include <unordered_set>

#include "db_api/include/MysqlAccess.h"
#include "data_shadow/include/data_translate.h"
#include "svm_db.h"

#ifdef HANDLE_CMD
#undef HANDLE_CMD
#endif
#define HANDLE_CMD(x, y) do { \
  if (cmd.type == x) { \
    code = y(cmd, map, out_msg); \
    return code; \
  } \
} while (0)

subway_app *subway_app::p_instance = nullptr;

static std::string GetUsbRootPath(void)
{
  std::string usb_path = "";
  long usb_size = 0L;
  long usb_free = 0L;
  bool rec_usb = GetRecordPathAndSize("usbdisk", usb_path, usb_size,
      usb_free);
  return usb_path;
}

static bool test_disk_full(void)
{
  bool rc = false;
  std::string cmd_str = "touch /tmp/.test_full";
  std::string buf = "";
  int ret = vpSystem::Instance()->call_cmd(cmd_str.data(), buf, 0);
  if (ret < 0) rc = true;
  system("rm -f /tmp/.test_full");
  return rc;
}

subway_app::subway_app(void)
{
  is_upgrading = false;
  tele_upgrading = false;
  hap_upgrading = false;
  copy_task.percent = 0;
  copy_task.state = 1;
  is_copying = false;
}

/*
login           : username password
register        : username password email
reset_password  : username password new_password email session_token
logout          : session_token

curl -d '{ "cmd_type": "login", "username": "zy", "password": "7096574cebeb85403bd77a8f6cbe151f","email":"test@qq.com"}' http://127.0.0.1:8081/apiserver/cmd
curl -d '{ "cmd_type": "register", "username": "zy", "password": "7096574cebeb85403bd77a8f6cbe151f","email":"test@qq.com"}' http://127.0.0.1:8081/apiserver/cmd
curl -d '{ "cmd_type": "reset_password", "username": "zy", "password": "7096574cebeb85403bd77a8f6cbe151f","new_password":"" ,"email":"test@qq.com","session_token":""}' http://127.0.0.1:8081/apiserver/cmd
curl -d '{ "cmd_type": "logout", "session_token":""}' http://127.0.0.1:8081/apiserver/cmd

*/
std::string subway_app::Handle(Command &cmd)
{
  AINFO << __func__ << " enter " ;
  int rc = 1;
  std::string msg = "失败";
  int code;
  Json::Value root, map;
  std::string out_msg = "";

  //识别客户端类型
  int type = IdentifyClient(cmd);
  AINFO << "type: " << type ;

  //获取会话令牌
  std::string session_token = BufferParser::Instance()->FindValueByKey(cmd, "session_token");
  AINFO << "session_token: " << session_token;

  if(!svm_db::Instance()->ValidateSession(session_token.c_str())) 
  {
    AINFO << "Session token invalid, checking user registration ";

    std::string input_username = BufferParser::Instance()->FindValueByKey(cmd, "username");
    AINFO << "input_username: " << input_username;

    if(!svm_db::Instance()->IsUsernameExist(input_username.c_str())) {
      AINFO << "User not registered, requesting registration";
      if(BufferParser::Instance()->FindValueByKey(cmd, "cmd_type") != "register") {
        //用户不存在且不是注册指令：提示用户进行注册 
        AINFO << "Not a register command, prompting registration";
        root["result_code"] = -1;
        root["result_msg"] = "User not registered, please register.";
        root["data_map"] = map.empty()? "{}" : map;
        Json::FastWriter writer;
        return writer.write(root);
      } else {
        code = Register(cmd, map, out_msg);
        AINFO << "Register command result: " << code << ", message: " << out_msg;
        root["result_code"] = code;
        root["result_msg"] = out_msg;
        root["data_map"] = map.empty()? "{}" : map;
        Json::FastWriter writer;
        return writer.write(root);
      }
    }

    //已注册，尝试登录
    AINFO << "User registered, trying to login";
    if(BufferParser::Instance()->FindValueByKey(cmd, "cmd_type") == "login") 
    {
      code = Login(cmd, map, out_msg);
      AINFO << "Login command result: " << code << ", message: " << out_msg;
      if(code != 0) 
      {
        root["result_code"] = code;
        root["result_msg"] = out_msg;
        root["data_map"] = map.empty()? "{}" : map;
        Json::FastWriter writer;
        return writer.write(root);
      }
      
      root["result_code"] = code;
      root["result_msg"] = out_msg;
      root["data_map"] = map.empty()? "{}" : map;
      //生成新令牌
      session_token = map["session_token"].asString();
      AINFO << "Login successful, new session token: " << session_token;
      
      Json::FastWriter writer;
      return writer.write(root);
    } 
    else 
    {
      AINFO << "Invalid session token, prompting login";
      root["result_code"] = -1;
      root["result_msg"] = "Session token invalid, please login.";
      Json::FastWriter writer;
      return writer.write(root);
    }
  }
  else 
  {
    AINFO << "Session token valid.";

    //处理命令
    code = PickHandle(cmd, map, out_msg, type);
  
    AINFO << "Command handling result: " << code << ", message: " << out_msg;
    root["result_code"] = code;
    root["result_msg"] = out_msg != "" ? out_msg : msg;
    root["data_map"] = map.empty() ? "{}" : map;
    
    Json::FastWriter writer;
    return writer.write(root);
  }
}


int subway_app::PickHandle(Command &cmd, Json::Value &map,
    std::string &out_msg, int client_type)
{
  int code = 404;

  std::string cmd_type = BufferParser::Instance()->FindValueByKey(cmd, "cmd_type");
  //无权限指令集合
  static const std::unordered_set<std::string> cidi_no_permissions = {
    "delete_user",
  };
  if(client_type == CLIENT_CIDI && cidi_no_permissions.find(cmd_type) != cidi_no_permissions.end())
  {
    out_msg = "Permission denied.";
    AINFO << "Permission denied for CIDI user on cmmmand: " << cmd_type;
    return -1;
  }
  

  HANDLE_CMD("login", Login);

  HANDLE_CMD("register", Register);

  HANDLE_CMD("reset_password", ResetPassword);

  HANDLE_CMD("logout", Logout);

  HANDLE_CMD("delete_user", DeleteUser);

  HANDLE_CMD("query_status", QueryStatus);

  HANDLE_CMD("get_sensor_state", GetSensorState);

  HANDLE_CMD("get_internal_info", GetInternalInfo);

  HANDLE_CMD("get_external_info", GetExternalInfo);

  HANDLE_CMD("get_record_date_list", GetRecordDateList);

  HANDLE_CMD("get_log_date_list", GetLogDateList);

  HANDLE_CMD("show_record_date_list", ShowRecordDateList);
  HANDLE_CMD("show_record_date_list_noJPG", ShowRecordDateListWithoutJPG);

  HANDLE_CMD("show_record_date_list_range", ShowRecordDateListWithTimeFilter);
  HANDLE_CMD("show_record_date_list_range_noJPG", ShowRecordDateListWithoutJPGWithTimeFilter);

  HANDLE_CMD("show_log_date_list", ShowLogDateList);

  HANDLE_CMD("record_range_copy", RecordDateCopy);

  HANDLE_CMD("log_date_copy", LogDateCopy);

  HANDLE_CMD("get_copy_progress", QueryCopyProgress);

  HANDLE_CMD("get_log_copy_progress", QueryLogCopyProgress);

  HANDLE_CMD("fw_import_upgrade", FirmwareImportAndUpgrade);

  HANDLE_CMD("version_query", FirmwareVersionQuery);

  HANDLE_CMD("version_rollback", FirmwareVersionRollback);

  HANDLE_CMD("reboot", SystemReboot);

  HANDLE_CMD("query_upgrade_progress", QueryUpgradeProgress);

  HANDLE_CMD("get_version_info", GetVersionInfo);

  HANDLE_CMD("download_calibparam", DownloadCalibrationParams);

  HANDLE_CMD("format_external", FormatExternalHdd);

  HANDLE_CMD("query_format_progress", QueryFormatProgress);

  HANDLE_CMD("map_import", MapImport);

  HANDLE_CMD("map_import_progress", MapQueryCopyProgress);

  HANDLE_CMD("model_import", ModelImport);

  HANDLE_CMD("calibration_start", CalibrationStart);

  HANDLE_CMD("calibration_status", CalibrationStatus);

  HANDLE_CMD("tele_upgrade_start", TeleUpgradeStart);

  HANDLE_CMD("tele_upgrade_status", TeleUpgradeStatus);

  HANDLE_CMD("hap_upgrade_start", HapUpgradeStart);

  HANDLE_CMD("hap_upgrade_status", HapUpgradeStatus);

  return code;
}


int subway_app::IdentifyClient(Command &cmd)
{
  std::string usrname_admin = "admin";
  // admin123
  //  std::string password_admin = "0192023a7bbd73250516f069df18b500";
  std::string password_admin = "c4ca4238a0b923820dcc509a6f75849b";

  std::string username_cidi = "cidi";
  // admin@cidi
  //  std::string password_cidi = "579888e426913d27cf6f0dbc514d0bc7";
  std::string password_cidi = "c4ca4238a0b923820dcc509a6f75849b";

  std::string input_usrname =
    BufferParser::Instance()->FindValueByKey(cmd,"username");
  std::string input_password =
    BufferParser::Instance()->FindValueByKey(cmd,"password");

  if (usrname_admin == input_usrname && password_admin == input_password)
    return CLIENT_ADMIN;
  else if (username_cidi == input_usrname && password_cidi == input_password)
    return CLIENT_CIDI;
  return CLIENT_CIDI;
}


int subway_app::Login(Command &cmd, Json::Value &map, std::string &out_msg)
{
  AINFO << __func__ << " enter " ;
  
  std::string input_username = BufferParser::Instance()->FindValueByKey(cmd,"username");
  std::string input_password = BufferParser::Instance()->FindValueByKey(cmd,"password");
 
  //哈希密码
  int rc = svm_db::Instance()->Login((char*)input_username.c_str(),
      (char*)input_password.c_str());
 
  if(rc < 0) {
    if (rc == -1)
      out_msg = "Invalid username or password.";
    else if (rc == -2) 
      out_msg = "Database error during login.";
    else 
      out_msg = "Login failed.";
    return rc;
  }
  
  //token
  char *token = generate_random_string(32);;

  //更新会话令牌
  int rc1 = svm_db::Instance()->UpdateToken((char*)input_username.c_str(), token);
  if(rc1 != 0) {
    out_msg = "Failed to update session token.";
    return rc1;
  }
  //返回会话信息和用户角色
  switch(rc) {
    case CLIENT_ADMIN:
      map["role"] = "CLIENT_ADMIN";
      break;
    case CLIENT_CIDI:
      map["role"] = "CLIENT_CIDI";
      break;
    case CLIENT_UNKNOWN:
      map["role"] = "CLIENT_UNKNOWN";
      break;
    default:
      map["role"] = "CLIENT_UNKNOWN";
      break;
  }
  map["session_token"] = token;
  map["stream_url"] = "ws://svm.pingtai.cidiserver.com:41001";

  free(token);

  out_msg = "Login successful.";
  AINFO << "Login successful for user: " << input_username ;

  return 0;
}

int subway_app::Register(Command &cmd, Json::Value &map, std::string &out_msg)
{
  AINFO << __func__ << "enter" ;

  std::string input_username = BufferParser::Instance()->FindValueByKey(cmd, "username");
  std::string input_password = BufferParser::Instance()->FindValueByKey(cmd, "password");
  std::string input_email = BufferParser::Instance()->FindValueByKey(cmd, "email");

  //判断输入是否为空
  if(input_username.empty() || input_password.empty() || input_email.empty()) {
    out_msg = "Username, Password, and Email can not be empty. ";
    AINFO << "Registration failed." << out_msg ;
    return -1;
  }
  
  //用户名和邮箱唯一
  if(svm_db::Instance()->IsUsernameExist(input_username.c_str())) {
    out_msg = "Username already exists.";
    AINFO << "Registration failed." << out_msg ;
    return -1;
  }

  if(svm_db::Instance()->IsEmailExist(input_email.c_str())) {    
    out_msg = "Email already exists.";
    AINFO << "Registration failed." << out_msg;
    return -1;
  }

  //保存信息到数据库
  int rc = svm_db::Instance()->Register(input_username.c_str(), input_password.c_str(), input_email.c_str());
  if(rc != 0) {
    out_msg = "Failed to register user.";
    AINFO << "Registration failed." << out_msg ;
    return -1;
  }

  out_msg = "Registration successful.";
  AINFO << "Registration successful for user:" << input_username ;
  return 0;
}

//重置密码
int subway_app::ResetPassword(Command &cmd, Json::Value &map, std::string &out_msg)
{
  std::string input_username = BufferParser::Instance()->FindValueByKey(cmd, "username");
  std::string input_email = BufferParser::Instance()->FindValueByKey(cmd, "email");
  std::string old_password = BufferParser::Instance()->FindValueByKey(cmd, "password");
  std::string new_password = BufferParser::Instance()->FindValueByKey(cmd, "new_password");
  
  if(input_email.empty() || old_password.empty() || new_password.empty()) {
    out_msg = "Email, old_password, and new_password cannot be empty.";
    AINFO << "Password reset failed. " << out_msg;
    return -1;
  }

  //哈希原密码和新密码
  //此处直接假定传输过来的数据是加密的

  //验证密码
  if(!svm_db::Instance()->Login(input_username.c_str(), old_password.c_str())) {
    out_msg = "Old password is incorrect.";
    AINFO << "Password reset failed. " << out_msg;
    return -1;
  }

  //验证邮箱是否存在
  if(!svm_db::Instance()->IsEmailExist(input_email.c_str())) {
    out_msg = "Email dose not exist.";
    AINFO << "Password reset failed: " << out_msg ;
    return -1;
  }

  int rc = svm_db::Instance()->UpdatePassword(input_username.c_str(), new_password.c_str());
  if(rc != 0) {
    out_msg = "Failed to update password.";
    AINFO << "Password reset failed." << out_msg;
    return -1;
  }

  out_msg = "Password has been reset successfully.";
  AINFO << out_msg;
  return 0;

}

int subway_app::Logout(Command &cmd, Json::Value &map, std::string &out_msg)
{
  std::string session_token = BufferParser::Instance()->FindValueByKey(cmd, "session_token");
  
  int rc = svm_db::Instance()->Logout(session_token.c_str());
  if(rc != 0) {
    out_msg = "Failed to logout";
    AINFO << "Logout failed: " << out_msg;
    return rc;
  }

  out_msg = "Logout successful";
  AINFO << out_msg;
  return 0;
}

int subway_app::DeleteUser(Command &cmd, Json::Value &map, std::string &out_msg)
{
  AINFO << __func__ << " enter ";

  std::string input_username = BufferParser::Instance()->FindValueByKey(cmd, "delete_username");

  if (input_username.empty())
  {
    out_msg = "Username cannot be empty.";
    AINFO << "Delete user failed. " << out_msg;
    return -1;
  }

  // 检查用户是否存在
  if (!svm_db::Instance()->IsUsernameExist(input_username.c_str()))
  {
    out_msg = "Username does not exist.";
    AINFO << "Delete user failed. " << out_msg;
    return -1;
  }

  // 删除用户
  int rc = svm_db::Instance()->DeleteUser(input_username.c_str());
  if (rc != 0)
  {
    if (rc == -1)
      out_msg = "Error finding username.";
    else if (rc == -2)
      out_msg = "Error deleting user.";
    else if (rc == -3)
      out_msg = "Error deleting user's sessions.";
    else
      out_msg = "Failed to delete user.";
    AINFO << "Delete user failed. " << out_msg;
    return rc;
  }

  out_msg = "User has been deleted successfully.";
  AINFO << out_msg;
  return 0;
}



int subway_app::QueryStatus(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  std::string data = "{";
  char *file_path = "/tmp/ips_system_state.txt";
  long size = get_file_length(file_path);;
  char *text = (char*)malloc(size + 1);
  if (!text) {
    AERROR << __func__ << " no more memory";
    return -3;
  }
  memset(text, 0x0, size + 1);
  int ret = read_file_context(file_path, text, size, "r");
  if (ret < 0) {
    AERROR << __func__ << " fail to read file, ret " << ret;
    return ret;
  }
  if (text) {
    data += text;
    free(text);
  }
  data += "}";
  Json::Reader reader;
  reader.parse(data, map);
  return 0;
}

int subway_app::GetSensorState(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  std::string data = "{";
  char *file_path = "/tmp/ips_sensor_state.txt";
  long size = get_file_length(file_path);;
  char *text = (char*)malloc(size + 1);
  if (!text) {
    AERROR << __func__ << " no more memory";
    return -3;
  }
  memset(text, 0x0, size + 1);
  int ret = read_file_context(file_path, text, size, "r");
  if (ret < 0) {
    AERROR << __func__ << " fail to read file, ret " << ret;
    return ret;
  }
  if (text) {
    data += text;
    free(text);
  }
  data += "}";
  Json::Reader reader;
  reader.parse(data, map);
  return 0;
}

int subway_app::GetInternalInfo(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  std::string data = "{";
  char *file_path = "/tmp/ips_internal_port_state.txt";
  long size = get_file_length(file_path);;
  char *text = (char*)malloc(size + 1);
  if (!text) {
    AERROR << __func__ << " no more memory";
    return -3;
  }
  memset(text, 0x0, size + 1);
  int ret = read_file_context(file_path, text, size, "r");
  if (ret < 0) {
    AERROR << __func__ << " fail to read file, ret " << ret;
    return ret;
  }
  if (text) {
    data += text;
    free(text);
  }
  data += "}";
  Json::Reader reader;
  reader.parse(data, map);
  return 0;
}

int subway_app::GetExternalInfo(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  std::string data = "{";

  char *file_path = "/tmp/ips_external_port_state.txt";
  long size = get_file_length(file_path);;
  char *text = (char*)malloc(size + 1);
  if (!text) {
    AERROR << __func__ << " no more memory";
    return -3;
  }
  memset(text, 0x0, size + 1);
  int ret = read_file_context(file_path, text, size, "r");
  if (ret < 0) {
    AERROR << __func__ << " fail to read file, ret " << ret;
    return ret;
  }
  if (text) {
    data += text;
    free(text);
  }
  data += "}";
  Json::Reader reader;
  reader.parse(data, map);
  return 0;
}

static void GetCopyDateList(std::string xx, int yy,
    std::vector<DateListItem> &vec)
{
  DIR *pdir = opendir((xx).data());
  struct dirent *pent;
  if (pdir) {
    while ((pent = readdir(pdir)) != NULL) {
      if ('.'==pent->d_name[0]||!strcmp(pent->d_name,"lost+found")) continue;
      if (DT_DIR == pent->d_type) {
        DateListItem item;
        item.name = pent->d_name;
        if (1 == yy) item.type = "alarm"; 
        else item.type = "time";
        vec.push_back(item);
      }
    }
    closedir(pdir);
  }
}

static bool DateListCompareSort(const DateListItem &v1, const DateListItem &v2)
{
  return (v1.name < v2.name);
}

static bool DateListCompareEqual(const DateListItem &v1,const DateListItem &v2)
{
  return (v1.name == v2.name);
}

int subway_app::GetRecordDateList(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  return GetDateList(cmd, 0, map, out_msg);
}

int subway_app::GetLogDateList(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  return GetDateList(cmd, 1, map, out_msg);
}

int subway_app::GetDateList(Command &cmd, int type, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;

  std::string root_path = "";
  std::vector<DateListItem> vec;
  vec.clear();
  long size = 0L;
  long free_size = 0L;
  int client_type = IdentifyClient(cmd);

  RecordLog(type, root_path, size, free_size, vec, 0);

  if (CLIENT_ADMIN == client_type) {
    RecordLog(type, root_path, size, free_size, vec, 1);
  }

  // Remove replace item.
  std::vector<DateListItem>::iterator iter;
  std::sort(vec.begin(), vec.end(), DateListCompareSort);
  iter = std::unique(vec.begin(), vec.end(), DateListCompareEqual);
  if (iter != vec.end())
    vec.erase(iter, vec.end());

  for (int i = 0; i < vec.size(); i++) {
    Json::Value item;
    item["name"] = vec[i].name;
    item["type"] = vec[i].type;
    map.append(item);
  }
  out_msg = "successful" ;
  return 0;
}

void subway_app::RecordLog(int type, std::string &root_path, long &size,
    long &free_size, std::vector<DateListItem> &vec, int flag)
{
  bool rec = false;

  // record
  if (0 == type) {
    root_path = "";
    size = free_size = 0L;
    rec = GetRecordPathAndSize(LOCAL_RECORD_PATH, root_path, size, free_size);
    if (rec) {
      if(flag == 1){
        GetCopyDateList(root_path + "/bag/", 0, vec);
      }
      GetCopyDateList(root_path + "/camera/full/", 0, vec);
      GetCopyDateList(root_path + "/camera/key/", 1, vec);
    }
  }
  // log
  else if (1 == type) {
    root_path = "";
    size = free_size = 0L;
    rec = GetLogPathAndSize(LOCAL_LOG_PATH, root_path, size, free_size);
    if (rec) {
      GetCopyDateList(root_path + "/ips/", 0, vec);
      GetCopyDateList(root_path + "/lte/", 0, vec);
    }
  }
}

//新增：查询录像、日志列表 cmd-携带数据 date: 20221215
// Function to list files in a directory and record their paths
static bool ShowCopyDateList(const std::string& dir, const std::string& base_path, std::vector<std::pair<std::string, std::string>>& vec, bool include_jpg) {
  AINFO << "Entering ShowCopyDateList for directory: " << dir ;
  DIR *pdir = opendir(dir.c_str());
  if (!pdir) {
    AINFO << "Failed to open directory: " << ", error: " << strerror(errno) << dir ;
    return false;
  }

  struct dirent *pent;
  while((pent = readdir(pdir)) != NULL) {
    std::string file_name(pent->d_name);
    std::string full_path = dir + "/" + file_name;
    if(pent->d_type == DT_REG) {
      std::string ext = file_name.substr(file_name.find_last_of('.')+1);
      if(ext != "ts" && file_name != "size.dat" && (include_jpg || ext != "jpg")) {
        vec.emplace_back(base_path, file_name);
      }
    } else if(pent->d_type == DT_DIR) {
      if(file_name != "." && file_name != "..") {
        // Recursively list files in subdirectories
        ShowCopyDateList(full_path, base_path + "/" + file_name, vec, include_jpg);
      }
    }
  }
  closedir(pdir);
  return true;
}

static bool ShowCopyDateListWithTimeFilter(const std::string& dir, const std::string& base_path, 
    std::vector<std::pair<std::string, std::string>>& vec, const std::string& start_time, const std::string& end_time, bool include_jpg) 
{
  AINFO << "Entering ShowCopyDateListWithTimeFilter for directory: " << dir ;
  DIR *pdir = opendir(dir.c_str());
  if (!pdir) {
    AINFO << "Failed to open directory: " << dir << ", error: " << strerror(errno) ;
    return false;
  }

  struct dirent *pent;
  while ((pent = readdir(pdir)) != NULL) {
    std::string file_name(pent->d_name);
    std::string full_path = dir + "/" + file_name;
    if(pent->d_type == DT_REG) {
      std::string ext = file_name.substr(file_name.find_last_of('.') + 1);
      std::string timestamp = file_name.substr(0, 17);
      if ((timestamp >= start_time) && (timestamp <= end_time)) {
        if (ext != "ts" && file_name != "size.dat" && (include_jpg || ext != "jpg")) {
          vec.emplace_back(base_path, file_name);
        }
      }
    } else if (pent->d_type == DT_DIR) {
      if(file_name != "." && file_name != "..") {
        ShowCopyDateListWithTimeFilter(full_path, base_path + "/" + file_name, vec, start_time, end_time, include_jpg);
      }
    }
  }
  closedir(pdir);
  return true;
}

static bool ShowCopyLogDateList(const std::string& dir, const std::string& base_path, std::vector<std::pair<std::string, std::string>>& vec) 
{
    AINFO << "Entering ShowCopyLogDateList for directory: " << dir;
    DIR *pdir = opendir(dir.c_str());
    if (!pdir) {
      AINFO << "Failed to open directory: " << ", error: " << strerror(errno) << dir ;
      return false;
    }
    struct dirent *pent;
    
    while ((pent = readdir(pdir)) != NULL) {
      std::string file_name(pent->d_name);
      std::string full_path = dir + "/" + file_name;

      if (pent->d_type == DT_REG) {
        vec.emplace_back(base_path, file_name);
      } else if (pent->d_type == DT_DIR) {
        if (file_name != "." && file_name != "..") {
          // Recursively list files in subdirectories
          ShowCopyLogDateList(full_path, base_path + "/" + file_name, vec);
        }
      }
    }
  closedir(pdir);
  return true;
  
}

int subway_app::ShowRecordDateList(Command &cmd, Json::Value & map, std::string &out_msg)
{
  AINFO << __func__ << " enter " ;
  return ShowDateList(cmd, 0, map, out_msg, true);
}

int subway_app::ShowRecordDateListWithoutJPG(Command &cmd, Json::Value & map, std::string &out_msg)
{
  AINFO << __func__ << " enter " ;
  return ShowDateList(cmd, 0, map, out_msg, false);
}

int subway_app::ShowRecordDateListWithTimeFilter(Command &cmd, Json::Value & map, std::string &out_msg)
{
  AINFO << __func__ << " enter " ;
  return ShowDateListWithTimeFilter(cmd, map, out_msg, true);
}

int subway_app::ShowRecordDateListWithoutJPGWithTimeFilter(Command &cmd, Json::Value & map, std::string &out_msg)
{
  AINFO << __func__ << " enter " ;
  return ShowDateListWithTimeFilter(cmd, map, out_msg, false);
}

int subway_app::ShowLogDateList(Command &cmd, Json::Value & map, std::string &out_msg)
{
  AINFO << __func__ << " enter ";
  return ShowDateList(cmd, 1, map, out_msg, true);
}

int subway_app::ShowDateList(Command &cmd, int type, Json::Value &map, std::string &out_msg, bool include_jpg) {
  AINFO << __func__ << " enter " ;

  std::string date_value = BufferParser::Instance()->FindValueByKey(cmd, "date");

  std::vector<std::pair<std::string, std::string>> vec;
  vec.clear();
  std::string root_path;
  long size = 0L;
  long free_size = 0L;
  int client_type = IdentifyClient(cmd);

  bool rc = ListDate(type, root_path, size, free_size, vec, 0, date_value, include_jpg);

  if (client_type == CLIENT_ADMIN) {
    rc = ListDate(type, root_path, size, free_size, vec, 1, date_value, include_jpg) || rc;
  }

  if (!rc) {
    out_msg = "Failed to list date";
    return -1;
  }

  // Remove duplicates
  std::sort(vec.begin(), vec.end());
  auto iter = std::unique(vec.begin(), vec.end());
  vec.erase(iter, vec.end());

  // Sort by folder, sort by file extension and then by file name
  std::sort(vec.begin(), vec.end(), [](const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
    if (a.first == b.first) {
      std::string ext_a = a.second.substr(a.second.find_last_of('.') + 1);
      std::string ext_b = b.second.substr(b.second.find_last_of('.') + 1);
      if (ext_a == ext_b) {
        return a.second < b.second;
      }
      return ext_a < ext_b;
    }
    return a.first < b.first;
  });

  Json::Value file_list(Json::arrayValue);
  for (const auto& item : vec) {
    Json::Value file_info;
    file_info["folder"] = item.first;
    file_info["file"] = item.second;
    file_list.append(file_info);
  }

  map["file_list"] = file_list;
  map["file_count"] = static_cast<int>(vec.size());

  out_msg = "Query success";
  return 0;
}

int subway_app::ShowDateListWithTimeFilter(Command &cmd, Json::Value &map, std::string &out_msg, bool include_jpg) 
{
  AINFO << __func__ << " enter ";

  std::string date_value = BufferParser::Instance()->FindValueByKey(cmd, "date");
  std::vector<std::string> name_list;
  split_string(date_value, date_value.size(), name_list, "|"); 

  date_value = date_value.substr(0,8);

  if(name_list.size() != 2 || name_list[0].length()!=14 || name_list[1].length()!=14) {
    out_msg = "Invalid date format";
    return -1;
  }
  std::string start_time = name_list[0];
  std::string end_time = name_list[1];

  std::vector<std::pair<std::string, std::string>> vec;
  vec.clear();
  std::string root_path;
  long size = 0L;
  long free_size = 0L;
  int client_type = IdentifyClient(cmd);

  bool rc = ListDateWithTimeFilter(root_path, size, free_size, vec, 0, date_value, start_time, end_time, include_jpg);

  if (client_type == CLIENT_ADMIN) {
    rc = ListDateWithTimeFilter(root_path, size, free_size, vec, 1, date_value, start_time, end_time, include_jpg) || rc;
  }

  if (!rc) {
    out_msg = "Failed to list date with time filter";
    return -1;
  }

  // Remove duplicates
  std::sort(vec.begin(), vec.end());
  auto iter = std::unique(vec.begin(), vec.end());
  vec.erase(iter, vec.end());

  // Sort by folder, sort by file extension and then by file name
  std::sort(vec.begin(), vec.end(), [](const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
    if (a.first == b.first) {
      std::string ext_a = a.second.substr(a.second.find_last_of('.') + 1);
      std::string ext_b = b.second.substr(b.second.find_last_of('.') + 1);
      if (ext_a == ext_b) {
        return a.second < b.second;
      }
      return ext_a < ext_b;
    }
    return a.first < b.first;
  });

  Json::Value file_list(Json::arrayValue);
  for (const auto& item : vec) {
    Json::Value file_info;
    file_info["folder"] = item.first;
    file_info["file"] = item.second;
    file_list.append(file_info);
  }

  map["file_list"] = file_list;
  map["file_count"] = static_cast<int>(vec.size());

  out_msg = "Query success";
  return 0;
}

bool subway_app::ListDate(int type, std::string &root_path, long &size, long &free_size, std::vector<std::pair<std::string, std::string>>& vec, int flag, std::string &date_value, bool include_jpg)
{
  AINFO << __func__ << " enter " ;

  bool rec = false; 
  bool success = false;

  //record
  if(0 == type) {
    root_path = "";
    size = free_size = 0L;
    rec = GetRecordPathAndSize(LOCAL_RECORD_PATH, root_path, size, free_size);
    AINFO << "root_path = " << root_path;

    if(rec) {
      if(flag == 1){
        success = ShowCopyDateList(root_path + "/bag/" + date_value, date_value + "/", vec, include_jpg) || success;
      }
      success = ShowCopyDateList(root_path + "/camera/full/" + date_value, date_value + "/", vec, include_jpg) || success;
      success = ShowCopyDateList(root_path + "/camera/key/" + date_value, date_value + "/", vec, include_jpg) || success;
    }
  }
  //log
  else if (1==type) {
    root_path = "";
    size = free_size = 0L;
    rec = GetRecordPathAndSize(LOCAL_LOG_PATH, root_path, size, free_size);
    AINFO << "root_path = " << root_path;
    if(rec) {
      success = ShowCopyLogDateList(root_path + "/ips/" + date_value + "/", date_value + "/", vec) || success;
      success = ShowCopyLogDateList(root_path + "/lte/" + date_value + "/", date_value + "/", vec) || success;
    }
  }

  if( !success ) {
    AINFO << "Failed to list date for type " << type ;
  }

  return success;
}

bool subway_app::ListDateWithTimeFilter(std::string &root_path, long &size, long &free_size, std::vector<std::pair<std::string, std::string>>& vec, int flag, std::string &date_value, const std::string& start_time, const std::string& end_time, bool include_jpg) {
  AINFO << __func__ << " enter " ;

  bool rec = false; 
  bool success = false;
  
  root_path = "";
  size = free_size = 0L;
  rec = GetRecordPathAndSize(LOCAL_RECORD_PATH, root_path, size, free_size);
  AINFO << "root_path = " << root_path ;

  if(rec) {
    if (flag == 1) {
      success = ShowCopyDateListWithTimeFilter(root_path + "/bag/" + date_value, date_value + "/", vec, start_time, end_time, include_jpg) || success;
    }
    success = ShowCopyDateListWithTimeFilter(root_path + "/camera/full/" + date_value, date_value + "/", vec, start_time, end_time, include_jpg) || success;
    success = ShowCopyDateListWithTimeFilter(root_path + "/camera/key/" + date_value, date_value + "/", vec, start_time, end_time, include_jpg) || success;
  }
  
  if (!success) {
    AINFO << "Failed to list date with time filter " ;
  }

  return success;
}





int subway_app::RecordDateCopy(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  return DateCopy(cmd, 0, map, out_msg);
}

int subway_app::LogDateCopy(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  return DateCopy(cmd, 1, map, out_msg);
}

int subway_app::DateCopy(Command &cmd, int type, Json::Value &map,
    std::string &out_msg)
{
  int ret = 0;
  AINFO << __func__ << " enter" << std::endl;
  if (is_copying) {
    AINFO << " is copying\n";
    ret = 0;
    out_msg = "上一个拷贝任务正在进行中";
  }
  else {
    std::string usb_root = GetUsbRootPath();
    if (usb_root.empty()) {
      out_msg = "请介入U盘";
      ret = 2;
    }
    else {
    is_copying = true;
    BufferParser::Instance()->CopyCommand(copy_command, cmd);
    copy_task.type = type;
    copy_task.ix_from.clear();
    copy_task.ix_to.clear();
    copy_task.ex_from.clear();
    copy_task.ex_to.clear();
    ACTIVATE_THREAD(&subway_app::CopyHandler, this);
    ret = 0;
    out_msg = "任务添加成功，开始拷贝";
    }
  }
  return ret;
}

void* subway_app::CopyHandler(void *param)
{
  auto start_time = std::chrono::high_resolution_clock::now();
  AINFO << "现在开始计时 开始时间为： " << std::chrono::duration_cast<std::chrono::seconds>(start_time.time_since_epoch()).count();
  
  AINFO << __func__ << " enter\n";
  int rc = 1;
  int type = copy_task.type;
  copy_task.state = 0;
  int client_type = IdentifyClient(copy_command);
  std::string value = BufferParser::Instance()->FindValueByKey(copy_command,"date");
  std::vector<std::string> name_list;
  split_string(value, value.size(), name_list, "|");

  std::string usb_path = "";
  long usb_size = 0L;
  long usb_free = 0L;
  bool rec_usb = GetRecordPathAndSize("usbdisk", usb_path, usb_size,
      usb_free);
  AINFO << __func__ << " usbdisk state " << rec_usb << " path " << usb_path <<
      " size " << usb_size << " free " << usb_free << std::endl;
  
  if (rec_usb) {
    std::string root_path = usb_path + "/" + SUBWAY_COPY_ROOT_NAME;
    if (access(root_path.data(), F_OK) != 0) {
      if (makeDir(root_path))
        rec_usb = true;
      else {
        rec_usb = false;
        AERROR << "fail mkdir " << root_path << "\n";
      }
    }
    else rec_usb = true;
  }

  if (rec_usb)
    rc = RealCopy(type, client_type, rc, usb_path, usb_free, name_list);
  else rc = 2;

  copy_task.state = rc;
  is_copying = false;
  AINFO << __func__ << " exit state " << rc;

  auto end_time = std::chrono::high_resolution_clock::now();
  auto full_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
  AINFO << "现在结束 结束时间为" << std::chrono::duration_cast<std::chrono::seconds>(end_time.time_since_epoch()).count();
  AINFO << "总共耗时：" << full_time << "秒" << std::endl;

  return NULL;
}

#if 0
int subway_app::RealCopy(int type, int client_type, int &rc,
    std::string &usb_path, long &usb_free, std::vector<std::string> &name_list)
{
  system("touch /tmp/copying_file");
  copy_task.percent = 0;
  copy_task.total_size = 0L;
  copy_task.start_ts = time(NULL);

  std::string ex_camera, ex_log, ix_bag, ix_log;
  ex_camera = ex_log = ix_bag = ix_log = "";

  std::string path = "";
  long size, free_s;
  size = free_s = 0L;
  bool usrdisk_rec = false;
  bool rec;
  // record
  if (0 == type) {
    usrdisk_rec = GetRecordPathAndSize(LOCAL_RECORD_PATH, path, size, free_s);
    if (usrdisk_rec) {
      if (CLIENT_ADMIN == client_type)
        AppendRecordCopyFromPath(path + "/bag/", true, name_list, false);
      AppendRecordCopyFromPath(path + "/camera/full/", false, name_list, true);
      AppendRecordCopyFromPath(path + "/camera/key/", false, name_list, true);
    }
  }
  // log
  else if (1 == type) {
    size = free_s = 0L;
    rec = GetLogPathAndSize(LOCAL_LOG_PATH, path, size, free_s);
    if (rec) {
      AppendCopyFromPath(path + "/ips/", false, name_list);
      AppendCopyFromPath(path + "/lte/", false, name_list);
    }
  }

  for (int i = 0; i < copy_task.ex_from.size(); i++)
    AppendCopyToPath(copy_task.ex_from[i], false, usb_path);

  if (CLIENT_ADMIN == client_type) {
    path = "";
    if (0 == type) {
      size = free_s = 0L;
      rec = GetRecordPathAndSize("internaldisk", path, size, free_s);
      if (rec) {
        if (!usrdisk_rec) {
          AppendRecordCopyFromPath(path + "/bag/", true, name_list, false);
          AppendRecordCopyFromPath(path + "/camera/full/", true, name_list,
              true);
          AppendRecordCopyFromPath(path + "/camera/key/", true, name_list,
              true);
        }
      }
    }
    else if (1 == type) {
      size = free_s = 0L;
      rec = GetLogPathAndSize("internaldisk", path, size, free_s);
      if (rec) {
        AppendCopyFromPath(path + "/ips/", true, name_list);
        AppendCopyFromPath(path + "/lte/", true, name_list);
      }
    }
    for (int i = 0; i < copy_task.ix_from.size(); i++)
      AppendCopyToPath(copy_task.ix_from[i], true, usb_path);
  }
#if 1
  for (int i = 0; i < copy_task.ex_from.size(); i++)
    AINFO << "ex_from: i " << i << " v " <<copy_task.ex_from[i]<<"\n";
  for (int i = 0; i < copy_task.ex_to.size(); i++)
    AINFO << "ex_to: i " << i << " v " << copy_task.ex_to[i]<<"\n";
  for (int i = 0; i < copy_task.ix_from.size(); i++)
    AINFO << "ix_from: i " << i << " v " <<copy_task.ix_from[i]<<"\n";
  for (int i = 0; i < copy_task.ix_to.size(); i++)
    AINFO << "ix_to: i " << i << " v " << copy_task.ix_to[i]<<"\n";
  AINFO << "total_size: " << copy_task.total_size << " usb_free: " << usb_free << std::endl;
#endif

  if (copy_task.ix_from.size() < 1 && copy_task.ex_from.size() < 1) {
    copy_task.state = rc = 4;
  }
  else if (copy_task.total_size < usb_free) {
    AINFO << "Copying...";
    int percent = 0;
    unsigned int exSize = copy_task.ex_to.size();
    unsigned int ixSize = copy_task.ix_to.size();
    for (int i = 0; i < exSize; i++) {
      if (0 == type && CLIENT_CIDI == client_type) {
        if (copy_task.ex_from[i].find(".avi", 48) == std::string::npos && 
            copy_task.ex_from[i].find(".mp4", 48) == std::string::npos) {
          continue;
        }
      }
      ExecuteCopyCommand(copy_task.ex_to[i], copy_task.ex_from[i]);
      percent = (i + 1) * 100 / (16 * ixSize + exSize);
      if(percent >= 100)
        copy_task.percent = 99;
      else
        copy_task.percent = percent;
      if(copy_task.ex_to.size() <= i+1 || copy_task.ex_to[i] != copy_task.ex_to[i+1]) {
        std::string cmdString = "sync ";
        std::string rtnString;
        cmdString += copy_task.ex_to[i];
        vpSystem::Instance()->call_cmd(cmdString.data(), rtnString, 1);
      }
    }
    if (CLIENT_ADMIN == client_type) {
      for (int i = 0; i < ixSize; i++) {
        ExecuteCopyCommand(copy_task.ix_to[i], copy_task.ix_from[i]);
        percent = (exSize + (i + 1) * 16) * 100 / (16 * ixSize + exSize);
        if(percent >= 100)
          copy_task.percent = 99;
        else
          copy_task.percent = percent;
        if(ixSize <= i+1 || copy_task.ix_to[i] != copy_task.ix_to[i+1]) {
          std::string cmdString = "sync ";
          std::string rtnString;
          cmdString += copy_task.ix_to[i];
          vpSystem::Instance()->call_cmd(cmdString.data(), rtnString, 1);
        }
      }
    }
    rc = 1;
  }

  else copy_task.state = rc = 3;
  AINFO << "Copy and sync done, code " << rc;
  copy_task.percent = 100;
  remove("/tmp/copying_file");
  return rc;
}
#endif

int subway_app::RealCopy(int type, int client_type, int &rc,
    std::string &usb_path, long &usb_free, std::vector<std::string> &name_list)
{
  system("touch /tmp/copying_file");
  copy_task.percent = 0;
  copy_task.total_size = 0L;
  copy_task.start_ts = time(NULL);
  
  std::string path = "";
  long size, free_s;
  size = free_s = 0L;
  bool rec;

  //record copy logic
  if(0 == type) {
    if(client_type == CLIENT_ADMIN || client_type == CLIENT_CIDI) {
      rec = GetRecordPathAndSize(LOCAL_RECORD_PATH, path, size, free_s);
      if(rec) {
        if(client_type == CLIENT_ADMIN) {
          AppendRecordCopyFromPath(path + "/bag/", false, name_list, false);
        }
        AppendRecordCopyFromPath(path + "/camera/full/", false, name_list, true);
        //AppendRecordCopyFromPath(path + "/camera/key/", false, name_list, true);
      }
    }
    if(client_type == CLIENT_ADMIN) {
      size = free_s = 0L;
      rec = GetRecordPathAndSize("internaldisk", path, size, free_s);
      if(rec) {
          AppendRecordCopyFromPath(path + "/bag/", true, name_list, false);
          AppendRecordCopyFromPath(path + "/camera/full/", true, name_list, true);
          //AppendRecordCopyFromPath(path + "/camera/key/", true, name_list, true);
        }
      }
    }
  //log copy logic
  else if(1 == type) {
    if(client_type == CLIENT_ADMIN || client_type == CLIENT_CIDI) {
      rec = GetLogPathAndSize(LOCAL_LOG_PATH, path, size, free_s);
      if(rec) {
        AppendCopyFromPath(path + "/ips/", false, name_list);
        AppendCopyFromPath(path + "/lte/", false, name_list);
      }
    }
    if(client_type == CLIENT_ADMIN) {
      size = free_s = 0L; 
      rec = GetLogPathAndSize("internaldisk", path, size, free_s);
      if (rec) {
        AppendCopyFromPath(path + "/ips/", true, name_list);
        AppendCopyFromPath(path + "/lte/", true, name_list);
      }
    }
  }

  for (int i = 0; i < copy_task.ex_from.size(); i++) {
    AppendCopyToPath(copy_task.ex_from[i], false, usb_path);
  }

  for (int i = 0; i < copy_task.ix_from.size(); i++) {
      AppendCopyToPath(copy_task.ix_from[i], true, usb_path);
  }

  #if 1
  for (int i = 0; i < copy_task.ex_from.size(); i++)
    AINFO << "ex_from: i " << i << " v " <<copy_task.ex_from[i]<<"\n";
  for (int i = 0; i < copy_task.ex_to.size(); i++)
    AINFO << "ex_to: i " << i << " v " << copy_task.ex_to[i]<<"\n";
  for (int i = 0; i < copy_task.ix_from.size(); i++)
    AINFO << "ix_from: i " << i << " v " <<copy_task.ix_from[i]<<"\n";
  for (int i = 0; i < copy_task.ix_to.size(); i++)
    AINFO << "ix_to: i " << i << " v " << copy_task.ix_to[i]<<"\n";
  AINFO << "total_size: " << copy_task.total_size << " usb_free: " << usb_free << std::endl;
  #endif

  if (copy_task.ix_from.size() < 1 && copy_task.ex_from.size() < 1) {
    copy_task.state = rc = 4;
  }
  else if(copy_task.total_size < usb_free) {
    AINFO << "Copying...";
    rc = ParallelRealCopy(type, client_type, rc, usb_path, usb_free, copy_task.ex_from, copy_task.ex_to, 
        copy_task.ix_from, copy_task.ix_to);

    //同步操作
    for(int i = 0; i < copy_task.ix_to.size(); i++) {
      if(copy_task.ix_to.size()<= i+1 || copy_task.ix_to[i] != copy_task.ix_to[i+1]){
        std::string cmdString = "sync";
        std::string rtnString;
        cmdString += copy_task.ix_to[i];
        vpSystem::Instance()->call_cmd(cmdString.data(), rtnString, 1);
      }    
    }  
  }
  else {
    copy_task.state = rc =3;
  }
  
  AINFO << "Copy and sync done, code " << rc;
  copy_task.percent = 100;
  remove("/tmp/copying_file");
  return rc;
}

void subway_app::ExecuteCopyCommand(std::string xx, std::string yy)
{
  bool is_allow = false;
  std::string target_dir = xx.substr(0, xx.find_last_of('/'));

  if (access(target_dir.c_str(), F_OK) != 0) {
    is_allow = makeDir(xx.c_str());
  } else {
    is_allow = true;
  }
  
  if (is_allow) {
    std::string rtnString;
    std::string cmd = "rsync -a " + yy + " " + xx;
    AINFO << __func__ << " will execute cmd: " << cmd;
    vpSystem::Instance()->call_cmd(cmd, rtnString, 1);
  }

}


static void CopyBatchFiles(const std::vector<std::pair<std::string, std::string>>& files, std::atomic<int>& task_state) {
  for(const auto& file : files) {
    subway_app::ExecuteCopyCommand(file.second, file.first);
    task_state++;
  }
}

int subway_app::ParallelRealCopy(int type, int client_type, int& rc, const std::string& usb_path, 
    long usb_free, std::vector<std::string>& ex_from, std::vector<std::string>& ex_to, std::vector<std::string>& ix_from, std::vector<std::string>& ix_to)
{
  std::atomic<int> task_state(0);
  std::vector<std::thread> threads;
  unsigned int exSize = ex_from.size();
  unsigned int ixSize = ix_from.size();
  size_t batchSize = 10; //批量处理10个文件

//外部文件
  std::vector<std::pair<std::string, std::string>> batch;
  for (unsigned int i = 0; i < exSize; i++) {
      batch.emplace_back(ex_from[i], ex_to[i]);
      if(batch.size() == batchSize) {
        threads.emplace_back(CopyBatchFiles, batch, std::ref(task_state));
        batch.clear();
      }
  }
  if(!batch.empty()) {
    threads.emplace_back(CopyBatchFiles, batch, std::ref(task_state));
    batch.clear();
  }

//内部文件
  if (client_type == CLIENT_ADMIN) {
      batch.clear();
      for (unsigned int i = 0; i < ixSize; i++) {
        batch.emplace_back(ix_from[i], ix_to[i]);
        if(batch.size() == batchSize) {
          threads.emplace_back(CopyBatchFiles, batch, std::ref(task_state));    
          batch.clear();
        }
      }
  }  
  if(!batch.empty()) {
    threads.emplace_back(CopyBatchFiles, batch, std::ref(task_state));
    batch.clear();
  }

//等待线程结束
  for(auto& thread : threads) {
    if(thread.joinable()) {
      thread.join();
    }
  }
 
 //保证所有任务完成
  if (task_state == exSize + ixSize) {
      rc = 1;
  } else {
      rc = 0;
  }

  return rc; 

}


void subway_app::AppendCopyFromPath(std::string xx, bool yy,
    std::vector<std::string> &name_list)
{
  for (int i = 0; i < name_list.size(); i++) {
    std::string full_path = xx + "/" + name_list[i];
    if (!access(full_path.c_str(), F_OK)) {
      if (yy) copy_task.ix_from.push_back(full_path);
      else copy_task.ex_from.push_back(full_path);
      copy_task.total_size += GetFolderSize(full_path);
    }
  }
}

void subway_app::AppendRecordCopyFromPath(std::string xx, bool is_internal,
    std::vector<std::string> &name_list, bool is_video)
{
  if (2 != name_list.size()) return;

  // 20230718212500|20230718212700
  std::string start_time = name_list[0];
  std::string end_time = name_list[1];
  if (start_time.length() < 11) return;
  std::string date_str = start_time.substr(0, 8);
  int st_day = std::stoi(start_time.substr(6, 2));
  int st_hour = std::stoi(start_time.substr(8, 2));
  int st_min = std::stoi(start_time.substr(10, 2));
  int et_day = std::stoi(end_time.substr(6, 2));
  int et_hour = std::stoi(end_time.substr(8, 2));
  int et_min = std::stoi(end_time.substr(10, 2));
  int st_count = st_hour * 60 + st_min;
  int et_count = et_hour * 60 + et_min;

  std::vector<std::string> path_list;
  path_list.clear();
  std::string data_path = xx + date_str + "/";
  if (is_video) {
    data_path = xx + date_str + "/6mm/";
    path_list.push_back(data_path);
    data_path = xx + date_str + "/.res/";
    path_list.push_back(data_path);
  }
  else {
    path_list.push_back(data_path);
  }

  for(int i = 0; i < path_list.size(); i++) {
    struct dirent **namelist = NULL;
    char buf[32] = {0};

    int n = scandir(path_list[i].c_str(), &namelist, NULL, alphasort);
    if (n < 0) {
      perror("scandir");
      AERROR << __func__ << " scandir() " << path_list[i];
      continue;
    }
    else {
      while (n--) {
        //printf("%s\n", namelist[n]->d_name);
        if ('.' == namelist[n]->d_name[0]) continue;

        std::string filename = namelist[n]->d_name;
        bool valid = false;
        int cur_day = 0, cur_hour = 0, cur_min = 0;

        if(is_video) {
          //视频文件的日期时间处理
          if(filename.find(".avi") != std::string::npos || filename.find(".mp4") != std::string::npos) {
            std::string time_part = filename.substr(6,15);
            cur_day = std::stoi(time_part.substr(0,2));
            cur_hour = std::stoi(time_part.substr(2,2));
            cur_min = std::stoi(time_part.substr(4,2));
            valid = true;
          }
        } else {
          // .bag文件的处理
          // subway_2024-08-08-14-22-17_483.bag
          if(filename.find(".bag") != std::string::npos) {
            size_t start_pos = filename.find('_') + 1;
            std::string time_part = filename.substr(start_pos,19);
            cur_day = std::stoi(time_part.substr(8,2));
            cur_hour = std::stoi(time_part.substr(11,2));
            cur_min = std::stoi(time_part.substr(14,2));
            valid = true;
          }
        }

        if(!valid) {
          free(namelist[n]);
          continue;
        }

        int cur_count = cur_hour * 60 + cur_min;

        if(cur_day < st_day || cur_day > et_day) {
          free(namelist[n]);
          continue;
        }

        if (cur_count < st_count | cur_count > et_count) {
          free(namelist[n]);
          continue;
        }

        std::string full_path = path_list[i] + namelist[n]->d_name;
        
        if (is_internal) copy_task.ix_from.push_back(full_path);
        else copy_task.ex_from.push_back(full_path);
        
        copy_task.total_size += GetFolderSize(full_path);

        free(namelist[n]);
      }
      free(namelist);
    }
  }
}

bool subway_app::AppendCopyToPath_COMMON(std::string xx, bool yy,
    std::string &usb_path, std::string media_root)
{
  bool ret = false;
  int pos = xx.find(media_root);
  if (pos >= 0) {
    std::string parted_path;
    parted_path = xx.substr(pos + strlen(media_root.data()));

    if ('/' == parted_path.back()) parted_path.erase(parted_path.back());
    pos = parted_path.find_last_of("/");
    if (pos) {
      parted_path = parted_path.substr(0, pos);

      std::string root_name = "userdisk/";
      if (yy) root_name = "internaldisk/";

      std::string dst_path = usb_path + "/" + SUBWAY_COPY_ROOT_NAME + "/" +
        root_name + parted_path;

      if (yy) copy_task.ix_to.push_back(dst_path);
      else copy_task.ex_to.push_back(dst_path);
      ret = true;
    }
  }
  return ret;
}

void subway_app::AppendCopyToPath(std::string xx, bool yy,
    std::string &usb_path)
{
  bool rc = AppendCopyToPath_COMMON(xx, yy, usb_path,
      SUBWAY_MEDIA_NVIDIA_ROOT_HEAD);
  if (!rc)
    AppendCopyToPath_COMMON(xx, yy, usb_path,
        SUBWAY_MEDIA_CIDI_ROOT_HEAD);
}



int subway_app::QueryCopyProgress(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  return QueryRealProgress(cmd, map, out_msg);
}

int subway_app::QueryLogCopyProgress(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  return QueryRealProgress(cmd, map, out_msg);
}

int subway_app::QueryRealProgress(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;

  int client_type = IdentifyClient(cmd);
  if (is_copying && copy_task.percent <= 100) {
    long total_size = copy_task.total_size;
    if (total_size < 1) 
      total_size = 1; 
    Json::Int64 value = total_size;
    map["total_size"] = value;
    long size = 0;
    for (int i = 0; i < copy_task.ex_to.size(); i++) {
      if (!access(copy_task.ex_to[i].data(), F_OK))
        size += GetFolderSize(copy_task.ex_to[i]);
    }
    if (CLIENT_CIDI == client_type) {
      for (int i = 0; i < copy_task.ix_to.size(); i++) {
        if (!access(copy_task.ix_to[i].data(), F_OK))
          size += GetFolderSize(copy_task.ix_to[i]);
      }
    }
    int percent = (size *1.0) / (total_size *1.0) * 100;
    if (percent > 100 || percent < 0) percent = 100;
    if (percent > copy_task.percent)
      copy_task.percent = percent;
    map["percent"] = copy_task.percent;
    value = time(NULL) - copy_task.start_ts;
    map["seconds"] = value;
  }
  else {
    map["total_size"] = 1;
    map["percent"] = 100;
    map["seconds"] = 0;
  }
  int rc = copy_task.state;
  if (!is_copying) copy_task.state = 1;

  if (0 == rc)
    out_msg = "正在拷贝";
  else if (1 == rc)
    out_msg = "未在拷贝";
  else if (2 == rc)
    out_msg = "USB写入失败";
  else if (3 == rc)
    out_msg = "USB空间不够";
  else if (4 == rc)
    out_msg = "无对应数据";
  return rc;
}

int subway_app::GetVersionInfo(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  int ret = 0;
  if (verInfo.sys_ver == "") {
    AINFO << __func__ << " enter" << std::endl;
    std::string config_file = "./params/subway/product.yml";
    if (0 != CheckYmlHeader(config_file)) ret = 1;

    cv::FileStorage fs(GetAbsolutePath(config_file), cv::FileStorage::READ);
    if (!fs.isOpened()) {
      AERROR << " fail to open file: " << config_file;
      ret = 1;
    }
    if (ret != 1) {
      std::string value = "";
      fs["device_name"] >> value;
      verInfo.dev_name = value;

      /*
      std::string cmd_str = "jetson_release |grep Jetpack | awk '{print $3}'";
      */
      //std::string cmd_str = "env_file=/etc/profile.d/jetson_env.sh; if [ -f /etc/profile.d/jtop_env.sh ]; then env_file=/etc/profile.d/jtop_env.sh; fi; . $env_file; env |grep JETSON_JETPACK | cut -d '=' -f 2";
      std::string cmd_str = "env |grep JETSON_JETPACK | cut -d '=' -f 2";
      vpSystem::Instance()->call_cmd(cmd_str.data(), value, 0);
      verInfo.sys_ver = value;

      value = "";
      fs["software_version"] >> value;
      verInfo.sw_ver = value;

      value = "";
      fs["mcu_version"] >> value;
      verInfo.mcu_ver = value;

      value = "";
      fs["system_model"] >> value;
      verInfo.sys_model = value;

      value = "";
      fs["hardware_model"] >> value;
      verInfo.hw_model = value;
      fs.release();
    }
  }

  map["device_name"] = verInfo.dev_name;
  map["system_version"] = verInfo.sys_ver;
  map["software_version"] = verInfo.sw_ver;
  map["mcu_software_version"] = verInfo.mcu_ver;
  map["hardware_version"] = verInfo.sys_model;
  map["hardware_id"] = verInfo.hw_model;
  return ret;
}

int subway_app::FirmwareImportAndUpgrade(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  int ret = 0;
  AINFO << __func__ << " enter" << std::endl;
  std::string usb_root = GetUsbRootPath();
  AINFO << __func__ << " usbroot " << usb_root;
  if (usb_root.empty()) ret = 2;
  if (!ret) {
    std::string file_path = usb_root + "/" + SUBWAY_IPS_FW_FILENAME;
    AINFO << __func__ << " file_path " << file_path;
    if (access(file_path.data(), F_OK) != 0) ret = 1;
    if (!ret) {
      if (test_disk_full()) ret = 4;
      if (!ret) {
        std::string cmd_str ="rm -rf /tmp/C*T0*; unzip -o -d /tmp/ " + file_path;
        std::string buf = "";
        //int ret = vpSystem::Instance()->call_cmd(cmd_str.data(), buf, 0);
        int ret = system(cmd_str.data());
        if (ret < 0) ret = 5;
        if (ret != 5) {
          is_upgrading = true;
          cmd_str = "cd /tmp/; bash ./C*T0*/update.sh";
          buf = "";
          //ret = vpSystem::Instance()->call_cmd(cmd_str.data(), buf, 0);
          ret = system(cmd_str.data());
	  FILE *fp = fopen("/tmp/.fw_up_code", "r");
	  if (fp) {
            char data[32] = {0};
	    fread(data, 1, sizeof(data), fp);
	    int code = atoi(data);
	    if (code >= 0 && code < 10) ret = code;
            fclose(fp);
	    remove("/tmp/.fw_up_code");
	  }
	  else ret = 6;
          is_upgrading = false;
          if (ret < 0) ret = 6;
        }
      }
    }
  }
  AINFO << __func__ << " ret " << ret << std::endl;
  return ret;
}

int GetPreviousVersion(std::string &date_folder, std::string &version)
{
  char data[128] = {0};
  int ret = readlink("/home/nvidia/ips", data, sizeof(data));
  if (ret < 0) return ret;
  if (strstr(data, "_init")) return 2;
  int len = strlen(data);
  if ('/' == data[len - 1]) data[len - 1] = '\0';
  std::string buf = data;
  date_folder = buf;

  // prev date folder
  std::string cmd_str = "ls /home/nvidia/ |grep ips_ | grep -v 'ips ->' |grep -v " + buf;
  ret = vpSystem::Instance()->call_cmd(cmd_str, buf, 0);
  int index = buf.find('\n');
  if (index > 0) buf.erase(index);
  if (!buf.empty()) {
    date_folder = buf;
    cmd_str = "cat /home/nvidia/" + date_folder + "/params/subway/product.yml |grep software_version | awk '{print $2}' | sed 's/\"//g'";
    buf = "";
    ret = vpSystem::Instance()->call_cmd(cmd_str, buf, 0);
    index = buf.find('\n');
    if (index > 0) buf.erase(index);
    version = buf;
  }
  return 0;
}

int subway_app::FirmwareVersionQuery(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  int ret = 0;
  std::string cmd_str;
  std::string buf = "";
  AINFO << __func__ << " enter" << std::endl;

  // prev version
  std::string date_folder = "";
  ret = GetPreviousVersion(date_folder, buf);
  map["prev_version"] = buf;

  // curr version
  cmd_str = "cat params/subway/product.yml |grep software_version | awk '{print $2}' | sed 's/\"//g'";
  ret = vpSystem::Instance()->call_cmd(cmd_str, buf, 0);
  int index = buf.find('\n');
  if (index > 0) buf.erase(index);
  map["curr_version"] = buf;

  // next version
  std::string usb_root = GetUsbRootPath();
  std::string file_path = usb_root + "/" + SUBWAY_IPS_FW_FILENAME;
  AINFO << __func__ << " file_path " << file_path;
  buf = "";
  if (!access(file_path.data(), F_OK) != 0) {
    cmd_str ="rm -rf /tmp/C*T0*; unzip -o -d /tmp/ " + file_path +
      "; cat /tmp/C*T0*/ips_*/params/subway/product.yml |grep software_version | awk '{printf $2}' | sed 's/\"//g' > /tmp/fw_ver";
    ret = system(cmd_str.data());
    FILE *fp = fopen("/tmp/fw_ver", "r");
    char data[128] = {0};
    if (fp) {
      fread(data, 1, sizeof(data), fp);
      fclose(fp);
      buf = data;
      index = buf.find('\n');
      if (index > 0) buf.erase(index);
    }
  }
  map["next_version"] = buf;
  AINFO << __func__ << " return " << ret << std::endl;
  return 0;
}

int subway_app::FirmwareVersionRollback(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  int ret = 1;
  std::string cmd_str;
  std::string buf = "";
  std::string date_folder = "";
  AINFO << __func__ << " enter" << std::endl;
  std::string ver = BufferParser::Instance()->FindValueByKey(cmd,"version");
  char data[128] = {0};
  ret = readlink("/home/nvidia/ips", data, sizeof(data));
  if (ret < 0) return 2;
  if (strstr(data, "_init")) return 2;

  // prev date folder
  ret = GetPreviousVersion(date_folder, buf);
  if (buf == ver) {
    cmd_str = "cd /home/nvidia;ln -snf /home/nvidia/" + date_folder + " ips";
    ret = vpSystem::Instance()->call_cmd(cmd_str, buf, 0);
  }
  else ret = 1;
  return ret;
}

int subway_app::SystemReboot(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  std::string buf = "";
  return CallSystemCmd("./bin/hardboot", buf, 0);
}

int subway_app::QueryUpgradeProgress(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  int ret = 0;
  if (is_upgrading) ret = 1;
  return ret;
}

int subway_app::FormatExternalHdd(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;

  if (is_formating) {
    AINFO << " is formating\n";
  }
  else {
    is_formating = true;
    char cmd[128] = {0};
    sprintf(cmd, "touch %s", FORMAT_USR_FLAG);
    system(cmd);
  }
  return 0;
}

int subway_app::QueryFormatProgress(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  int percent = 0;
  if (!access(FORMAT_USR_FLAG, F_OK))
    percent = 100;
  map["percent"] = percent;
  return 0;
}

int subway_app::DownloadCalibrationParams(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  std::string usb_root = GetUsbRootPath();
  if (usb_root.empty()) return 2;
  std::string file_path = usb_root + "/" + SUBWAY_IPS_PARAMS_FILENAME;
  if (access(file_path.data(), F_OK) != 0) return 1;
  if (test_disk_full()) return 4;

  std::string cmd_str = "if [ ! -d ./params/subway/calibrate ]; then mkdir ./params/subway/calibrate; fi; unzip -o -d ./params/subway/calibrate/ "
    + file_path;
  std::string buf = "";
  int ret = vpSystem::Instance()->call_cmd(cmd_str.data(), buf, 0);
  if (ret < 0) return 5;
  return 0;
}

int subway_app::MapImport(Command &cmd, Json::Value &map, std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  std::string usb_root = GetUsbRootPath();
  if (usb_root.empty()) return 2;
  std::string file_path = usb_root + "/" + SUBWAY_IPS_MAP_FILENAME;
  if (access(file_path.data(), F_OK) != 0) return 1;
  if (test_disk_full()) return 4;

  std::string cmd_str = "unzip -o -d /tmp/ " + file_path;
  std::string buf = "";
  int ret = vpSystem::Instance()->call_cmd(cmd_str.data(), buf, 0);
  if (ret < 0) return 5;

  cmd_str ="cp -rf /tmp/map_*/* /home/nvidia/factory/map/";
  ret = vpSystem::Instance()->call_cmd(cmd_str.data(), buf, 0);
  if (ret < 0) return 6;
  return 0;
}
  
int subway_app::MapQueryCopyProgress(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  std::string cmd_str = "ps aux |grep cp |grep map";
  std::string buf = "";
  int ret = vpSystem::Instance()->call_cmd(cmd_str.data(), buf, 0);
  if (ret < 0) return 1;
  return 0;
}

int subway_app::ModelImport(Command &cmd, Json::Value &map,
    std::string &out_msg)
{
  std::string usb_root = GetUsbRootPath();
  if (usb_root.empty()) return 2;
  std::string file_path = usb_root + "/" + SUBWAY_IPS_MODEL_FILENAME;
  if (access(file_path.data(), F_OK) != 0) return 1;
  if (test_disk_full()) return 4;

  std::string cmd_str = "unzip -o -d /tmp/ " + file_path;
  std::string buf = "";
  int ret = system(cmd_str.data());
  if (ret != 0) return 5;

  cmd_str ="cp -drf /tmp/model_*/* /home/nvidia/factory/model/";
  ret = system(cmd_str.data());
  if (ret != 0) return 6;

  return ret;
}

int subway_app::CalibrationStart(Command &cmd, Json::Value &map, std::string &out_msg)
{
  std::string cmd_str ="./scripts/calibrate.sh";
  std::string buf = "";
  AINFO << __func__ << " enter" << std::endl;
  //int ret = vpSystem::Instance()->call_cmd(cmd_str.data(), buf, 0);
  int ret = system(cmd_str.data());
  if (ret < 0) ret = 1;
  else ret = 0;

  AINFO << __func__ << " exit ret " << ret << std::endl;
  return ret;
}

int subway_app::CalibrationStatus(Command &cmd, Json::Value &map, std::string &out_msg)
{
  AINFO << __func__ << " enter" << std::endl;
  std::string cmd_str = "pidof lidar2train";
  std::string buf = "";
  int is_calibing = 0;
  int ret = system(cmd_str.data());
//  int ret = vpSystem::Instance()->call_cmd(cmd_str.data(), buf, 0);
  if (!ret)
    is_calibing = 1;
  map["status_code"] = is_calibing;

  ret = 0;
  char *config_file = "params/subway/calibrate/near2train.yml";
  if (access(config_file, F_OK) != 0)
    config_file = "params/subway/near2train.yml";
  long file_len = get_file_length(config_file);
  if (file_len < 5) {
    AERROR << " fail to open file: " << config_file;
    map["last_calibration_time"] = "未标定";
    ret = 3;
  }
  else {
    cv::FileStorage fs(GetAbsolutePath(config_file), cv::FileStorage::READ);
    std::string value = "";
    fs["error_code"] >> ret;

    fs["time"] >> value;
    map["last_calibration_time"] = value;
    fs.release();
  }

  AINFO << __func__ << " ret " << ret << std::endl;
  return ret;
}

std::string exec(const char *cmd) {
  std::array<char, 128> buffer;
  std::string result;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  return result;
}

int stop_ips() {
  int r = -1;
  if (system("touch /tmp/stop_ips") == 0) {
    r = atoi(exec("killall ips").data());
    if (r == 0 or r == 1) r = 0;
  }
  return r;
}

int stop_tele() {
  int r = -1;
  std::string cmd_str = "ps -aux | grep livox_ros_driver | grep -v livox_ros_driver2 | grep -v grep | awk '{print $2}'";
  std::string result = exec(cmd_str.data());
  if (result.empty()) {
    r = 0;
  } else {
    result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
    std::string pid = result;
    cmd_str = "kill " + pid;
    r = system(cmd_str.data());
  }
  return r;
}

int stop_hap() {
  int r = -1;
  std::string cmd_str = "ps -aux | grep livox_ros_driver2 | grep -v grep | awk '{print $2}'";
  std::string result = exec(cmd_str.data());
  if (result.empty()) {
    r = 0;
  } else {
    result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
    std::string pid = result;
    cmd_str = "kill " + pid;
    r = system(cmd_str.data());
  }
  return r;
}

std::string get_tele_sn() {
  std::string result;
  std::string cmd_str = "cat /home/nvidia/ips/src/livox_ros_driver_cidi/config/livox_lidar_sn.yml | grep sn | awk '{print $2}'";
  result = exec(cmd_str.data());
  result.erase(std::remove(result.begin(), result.end(), '"'), result.end());
  return result;
}

int subway_app::TeleUpgradeStart(Command &cmd, Json::Value &map, std::string &out_msg) {
  // 启动TELE固件升级
  /*ret = {
    0:"升级成功",
    1:"升级进行中",
    2:"未检测到U盘",
    3:"未检测到升级文件",
    4:"磁盘空间已满",
    5:"升级包解压失败",
    6:"ips关闭失败",
    7:"TELE驱动关闭失败,
    8:"TELE SN号获取失败"
  }*/
  int ret = 0;

  if (tele_upgrading) {
    ret = 1;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  AINFO << __func__ << " enter" << std::endl;
  std::string usb_root = GetUsbRootPath();
  AINFO << __func__ << " usbroot " << usb_root;
  if (usb_root.empty()) {
    ret = 2;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  std::string file_path = usb_root + "/" + SUBWAY_IPS_TELE_FW_FILENAME;
  AINFO << __func__ << " file_path " << file_path;
  if (access(file_path.data(), F_OK) != 0) {
    ret = 3;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  if (test_disk_full()) {
    ret = 4;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  std::string cmd_str = "rm -rf /tmp/tele_fw; unzip -o -d /tmp/ " + file_path;
  ret = system(cmd_str.data());
  if (ret != 0) {
    ret = 5;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  // 关闭ips
  int r = stop_ips();
  if (r != 0) {
    ret = 6;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  // 关闭tele驱动
  r = stop_tele();
  if (r != 0) {
    ret = 7;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  // 获取tele的SN号
  std::string tele_sn = get_tele_sn();
  if (tele_sn.empty()) {
    ret = 8;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  // 运行升级程序
  cmd_str = "cd /tmp; bash tele_fw/update.sh " + tele_sn;
  ret = system(cmd_str.data());

  if (ret == 0) tele_upgrading = true;

  return ret;
}

int subway_app::TeleUpgradeStatus(Command &cmd, Json::Value &map, std::string &out_msg) {
  // TELE固件升级状态查询
  /*{
    -1：打开文件失败
    0：升级成功
    1：升级失败
    2：固件与设备不匹配
    3：升级中
    4：无法获取升级状态
  }*/
  int ret = 4;

  FILE *fp = fopen("/tmp/tele_update_status", "r");
  if (fp) {
    fclose(fp);
    std::string cmd_str = "cd /tmp; cat tele_update_status | grep return | awk '{print $2}'";
    std::string result = exec(cmd_str.data());
    result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
    if (result != "") {
      ret = atoi(result.data());
      tele_upgrading = false;
      system("mv /tmp/tele_update_status /tmp/.tele_update_status_last");
    } else {
      ret = 3;
      tele_upgrading = true;
    }
  }

  return ret;
}

int subway_app::HapUpgradeStart(Command &cmd, Json::Value &map, std::string &out_msg) {
  // 启动HAP固件升级
  /*ret = {
    0:"启动成功"，
    1:"升级进行中",
    2:"未检测到U盘",
    3:"未检测到升级文件",
    4:"磁盘空间已满",
    5:"升级包解压失败",
    6:"ips关闭失败",
    7:"HAP驱动关闭失败
  }*/

  int ret = 0;

  if (hap_upgrading) {
    ret = 1;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  AINFO << __func__ << " enter" << std::endl;
  std::string usb_root = GetUsbRootPath();
  AINFO << __func__ << " usbroot " << usb_root;
  if (usb_root.empty()) {
    ret = 2;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  std::string file_path = usb_root + "/" + SUBWAY_IPS_HAP_FW_FILENAME;
  AINFO << __func__ << " file_path " << file_path;
  if (access(file_path.data(), F_OK) != 0) {
    ret = 3;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  if (test_disk_full()) {
    ret = 4;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  std::string cmd_str = "rm -rf /tmp/hap_fw; unzip -o -d /tmp/ " + file_path;
  ret = system(cmd_str.data());
  if (ret != 0) {
    ret = 5;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  // 关闭ips
  int r = stop_ips();
  if (r != 0) {
    ret = 6;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  // 关闭hap驱动
  r = stop_hap();
  if (r != 0) {
    ret = 7;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  // 运行升级程序
  cmd_str = "cd /tmp; bash hap_fw/update.sh";
  r = system(cmd_str.data());
  if (r == -1) {
    ret = 8;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  } else if (r == -2) {
    ret = 9;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  } else if (r == -3) {
    ret = 10;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  } else if (r == 139) {
    ret = 11;
    AINFO << __func__ << " ret " << ret << std::endl;
    return ret;
  }

  return ret;
}

int subway_app::HapUpgradeStatus(Command &cmd, Json::Value &map, std::string &out_msg) {
  // HAP固件升级状态查询
  /*
    4：无法获取升级状态
    3：升级中
    0：升级成功
    -1：启动时执行的指令参数个数不对
    -2：激光雷达初始化失败
    -3：升级用的固件文件打开失败
    -4：path == NULL && host_ip == NULL
    -5：Parse Cfg File error
    -6：Params Check error
    -7：Device manager init failed
    -8：Device manager init failed
    -9：激光雷达配置文件加载失败
    -10：激光雷达配置文件内容错误
    非数值：核心已转存，需查看输出记录定位问题
  */
  int ret = 4;

  FILE *fp = fopen("/tmp/hap_update_status", "r");
  if (fp) {
    fclose(fp);
    std::string cmd_str = "cd /tmp; cat hap_update_status | grep return | awk '{print $2}'";
    std::string result = exec(cmd_str.data());
    result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
    if (result != "") {
      ret = atoi(result.data());
      hap_upgrading = false;
      system("mv /tmp/hap_update_status /tmp/.hap_update_status_last");
    } else {
      ret = 3;
      hap_upgrading = true;
    }
  }

  return ret;
}

subway_app *subway_app::Instance() {
  if (nullptr == p_instance) p_instance = new subway_app();
  return p_instance;
}

void subway_app::ReleaseInstance() {}
