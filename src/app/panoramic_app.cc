#include "panoramic_app.h"
#include <iostream>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <opencv2/opencv.hpp>
#include "../config.h"
#include "common.h"

#define RECORD_ROOT_DIR "/media/cidi/data/record/"
//#define RECORD_ROOT_DIR "/home/zhang.hq/record/record"
#define URL_ROOT_DIR    "/www/"
#define PATH_NUM        4
#define RECORD_TYPE_NUM 3
#define RECORD_PER_PAGE 20

panoramic_app *panoramic_app::p_instance = nullptr;

std::string panoramic_app::Handle(Command &cmd)
{
  std::string result = "thank you call";

  HANDLE_CMD("login", Login);

  HANDLE_CMD("delete-record", FileRemove);

  HANDLE_CMD("get-record-info", FileList);
  HANDLE_CMD("get-record-page", GetFileListPage);

  HANDLE_CMD("get_vehicle_information", GetVehicleInformation);
  HANDLE_CMD("select_vehicle_information", SelectVehicleInformation);

  HANDLE_CMD("get_enhancement_status", GetEnhancementStatus);
  HANDLE_CMD("lane_departure_warning", LaneDepartureWarning);
  HANDLE_CMD("abnormal_behavior_detection", AbnormalBehaviorDetection);
  HANDLE_CMD("height_limit_monitoring", HeightLimitMonitoring);
  HANDLE_CMD("get_camera_status", GetCameraStatus);
  HANDLE_CMD("set_camera_status", SetCameraStatus);
  HANDLE_CMD("set_roi", SetROI);

  HANDLE_CMD("get_image_information", GetImageInformation);
  HANDLE_CMD("adjust_image_brightness", AdjustImageInformation);
  HANDLE_CMD("adjust_image_contrast", AdjustImageInformation);
  HANDLE_CMD("image_reset", AdjustImageInformation);

  HANDLE_CMD("factory_reset", FactoryReset);

  HANDLE_CMD("set-date-time", SetDateTime);
  HANDLE_CMD("get-sdcard-info", GetSDcardInfo);
  HANDLE_CMD("format-sdcard", FormatSDcard);
  HANDLE_CMD("change-password", ChangePassword);
  HANDLE_CMD("get-system-info", GetSystemInfo);
  HANDLE_CMD("get-log-info",GetLogInfo);

  // TODO:

  return result;
}

std::string panoramic_app::Login(Command &cmd)
{
  std::cout << __func__ << " enter" << std::endl;
  //Todo
  std::string returnStr ="";

  std::string usrname = "xhz";
  std::string password = "123";

  std::string input_usrname = BufferParser::Instance()->FindValueByKey(cmd,"username");
  std::string input_password = BufferParser::Instance()->FindValueByKey(cmd,"password");
  if ((usrname == input_usrname)&&(password == input_password))
  {
    returnStr+="{";
    returnStr+="\"result-code\":0,";
    returnStr+="\"result-msg\":\"登录成功\",";
    returnStr+="\"data-map\":";
    returnStr+="{";
    returnStr+="}";
    returnStr+="}";
  }
  else{
    returnStr+="{";
    returnStr+="\"result-code\":1,";
    returnStr+="\"result-msg\":\"登录失败\",";
    returnStr+="\"data-map\":";
    returnStr+="{";
    returnStr+="}";
    returnStr+="}";
  }
  
  return returnStr;
}

// 获取车辆的类型和颜色
std::string panoramic_app::GetVehicleInformation(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string type;
  std::string color;
  std::string returnStr = "";
  // TODO: 获取当前车辆的类型和颜色
  returnStr += "{\"result-code\": 0, \"result-msg\": \"操作成功\", \"data-map\": {\"vehicle-type\": \"";
  returnStr += type;
  returnStr += "\", ";
  returnStr += "\"vehicle-color\": \"";
  returnStr += color;
  returnStr += "\"}}";
  return returnStr;
}

// 选择车辆的类型和颜色
std::string panoramic_app::SelectVehicleInformation(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string vehicle_type = BufferParser::Instance()->FindValueByKey(cmd, "vehicle-type");
  std::string vehicle_color = BufferParser::Instance()->FindValueByKey(cmd, "vehicle-color");
  if ((vehicle_type == "truck" or vehicle_type == "bus") and
     (vehicle_color == "white" or vehicle_color == "blue")) {
    // TODO:选择车辆的类型和颜色
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  } else {
    return "{\"result-code\":1, \"result-msg\": \"参数错误\", \"data-map\": {}}";
  }
  return "{\"result-code\":1, \"result-msg\": \"参数错误\", \"data-map\": {}}";
}

// 获取各增强功能状态
std::string panoramic_app::GetEnhancementStatus(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string lane_departure_warning;
  std::string abnormal_behavior_detection;
  std::string height_limit_monitoring;
  cv::FileStorage fs_read;
  fs_read.open("../params/enhancement_status.yml",cv::FileStorage::READ);
  if (fs_read.isOpened()) {
    fs_read["lane_departure_warning"] >> lane_departure_warning;
    fs_read["abnormal_behavior_detection"] >> abnormal_behavior_detection;
    fs_read["height_limit_monitoring"] >> height_limit_monitoring;
  } else {
    std::cout << "There is no parameter file" << std::endl;
    return "{\"result-code\":1, \"result-msg\": \"操作失败\", \"data-map\": {}}";
  }
  fs_read.release();
  std::string returnStr = "";
  returnStr += "{\"result-code\": 0, \"result-msg\": \"操作成功\", \"data-map\": {";
  returnStr += "\"lane-departure-warning\": \"";
  returnStr += lane_departure_warning;
  returnStr += "\", ";
  returnStr += "\"abnormal-behavior-detection\": \"";
  returnStr += abnormal_behavior_detection;
  returnStr += "\", ";
  returnStr += "\"height-limit-monitoring\": \"";
  returnStr += height_limit_monitoring;
  returnStr += "\"}}";
  return returnStr;
}

// 更改增强功能的状态
std::string panoramic_app::ChangeEnhancementStatus(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string lane_departure_warning;
  std::string abnormal_behavior_detection;
  std::string height_limit_monitoring;
  cv::FileStorage fs_read, fs_write;
  // read params from enhancement_status.yml
  fs_read.open("../params/enhancement_status.yml",cv::FileStorage::READ);
  if (fs_read.isOpened()) {
    fs_read["lane_departure_warning"] >> lane_departure_warning;
    fs_read["abnormal_behavior_detection"] >> abnormal_behavior_detection;
    fs_read["height_limit_monitoring"] >> height_limit_monitoring;
  } else {
    std::cout << "There is no parameter file" << std::endl;
    return "{\"result-code\":1, \"result-msg\": \"操作失败\", \"data-map\": {}}";
  }
  fs_read.release();
  // change param value
  std::string value = BufferParser::Instance()->FindValueByKey(cmd, "action");
  if (cmd.type == "lane_departure_warning") {
    if (value == "open") {
      lane_departure_warning = "opened";
    } else if (value == "close") {
      lane_departure_warning = "closed";
    }
  } else if (cmd.type == "abnormal_behavior_detection") {
    if (value == "open") {
      abnormal_behavior_detection = "opened";
    } else if (value == "close") {
      abnormal_behavior_detection = "closed";
    }
  } else if (cmd.type == "height_limit_monitoring") {
    if (value == "open") {
      height_limit_monitoring = "opened";
    } else if (value == "close") {
      height_limit_monitoring = "closed";
    }
  }
  // write params to enhancement_status.yml
  fs_write.open("../params/enhancement_status.yml",cv::FileStorage::WRITE);
  if (fs_write.isOpened()) {
    fs_write << "lane_departure_warning" << lane_departure_warning;
    fs_write << "abnormal_behavior_detection" << abnormal_behavior_detection;
    fs_write << "height_limit_monitoring" << height_limit_monitoring;
  } else {
    std::cout << "There is no parameter file" << std::endl;
    return "{\"result-code\":1, \"result-msg\": \"操作失败\", \"data-map\": {}}";
  }
  fs_write.release();
  return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
}

// 车道偏离预警模块
std::string panoramic_app::LaneDepartureWarning(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string value = BufferParser::Instance()->FindValueByKey(cmd, "action");
  if (value == "open") {
    ChangeEnhancementStatus(cmd);
    // TODO: 开启车道偏离预警功能
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  } else if (value == "close") {
    ChangeEnhancementStatus(cmd);
    // TODO: 关闭车道偏离预警功能
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  }
  return "{\"result-code\":1, \"result-msg\": \"操作失败\", \"data-map\": {}}";
}

// 异常行为检测模块
std::string panoramic_app::AbnormalBehaviorDetection(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string value = BufferParser::Instance()->FindValueByKey(cmd, "action");
  if (value == "open") {
    ChangeEnhancementStatus(cmd);
    // TODO: 开启异常行为检测功能
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  } else if (value == "close") {
    ChangeEnhancementStatus(cmd);
    // TODO: 关闭异常行为检测功能
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  }
  return "{\"result-code\":1, \"result-msg\": \"操作失败\", \"data-map\": {}}";
}

// 获取各个摄像头ID的状态
std::string panoramic_app::GetCameraStatus(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string left_front;
  std::string front;
  std::string right_front;
  std::string left_rear;
  std::string rear;
  std::string right_rear;
  std::string returnStr = "";
  // TODO: 获取各摄像头状态
  returnStr += "{\"result-code\": 0, \"result-msg\": \"操作成功\", \"data-map\": {";
  returnStr += "\"left-front\": \"";
  returnStr += left_front;
  returnStr += "\", ";
  returnStr += "\"front\": \"";
  returnStr += front;
  returnStr += "\", ";
  returnStr += "\"right-front\": \"";
  returnStr += right_front;
  returnStr += "\", ";
  returnStr += "\"left-rear\": \"";
  returnStr += left_rear;
  returnStr += "\", ";
  returnStr += "\"rear\": \"";
  returnStr += rear;
  returnStr += "\", ";
  returnStr += "\"right-rear\": \"";
  returnStr += right_rear;
  returnStr += "\"}}";
  return returnStr;
}

// 更改摄像头ID的状态
std::string panoramic_app::SetCameraStatus(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string left_front = BufferParser::Instance()->FindValueByKey(cmd, "left-front");
  std::string front = BufferParser::Instance()->FindValueByKey(cmd, "front");
  std::string right_front = BufferParser::Instance()->FindValueByKey(cmd, "right-front");
  std::string left_rear = BufferParser::Instance()->FindValueByKey(cmd, "left-rear");
  std::string rear = BufferParser::Instance()->FindValueByKey(cmd, "rear");
  std::string right_rear = BufferParser::Instance()->FindValueByKey(cmd, "right-rear");
  // TODO: 设置摄像头ID状态
  return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
}

// 设置ROI时获取已选中里最靠前的摄像头ID
std::string panoramic_app::SetROI(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string camera_id;
  // TODO: 获取已选中里最靠前的摄像头ID
  std::string returnStr = "";
  returnStr += "{\"result-code\": 0, \"result-msg\": \"操作成功\", \"data-map\": {";
  returnStr += "\"camera-id\": \"";
  returnStr += camera_id;
  returnStr += "\"}}";
  return returnStr;
}

// 限高监控模块
std::string panoramic_app::HeightLimitMonitoring(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  std::string value = BufferParser::Instance()->FindValueByKey(cmd, "action");
  if (value == "open") {
    ChangeEnhancementStatus(cmd);
    // TODO: 开启限高监控功能
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  } else if (value == "close") {
    ChangeEnhancementStatus(cmd);
    // TODO: 关闭限高监控功能
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  }
  return "{\"result-code\":1, \"result-msg\": \"操作失败\", \"data-map\": {}}";
}

// 获取当前图像信息
std::string panoramic_app::GetImageInformation(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  double brightness_value;
  double contrast_value;
  // TODO: 获取图像的亮度与对比度值
  std::string image_brightness = std::to_string(brightness_value); // value转string
  std::string image_contrast = std::to_string(contrast_value); // value转string
  std::string returnStr = "";
  returnStr += "{\"result-code\": 0, \"result-msg\": \"操作成功\", \"data-map\": {";
  returnStr += "\"image-brightness\": \"";
  returnStr += image_brightness;
  returnStr += "\", ";
  returnStr += "\"image-contrast\": \"";
  returnStr += image_contrast;
  returnStr += "\"}}";
  return returnStr;
}

// 调整图像的亮度或对比度或者对它们进行重置
std::string panoramic_app::AdjustImageInformation(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
  if (cmd.type == "adjust_image_brightness")
  {
    std::string value = BufferParser::Instance()->FindValueByKey(cmd, "image-brightness");
    if (value == "") {
      return "{\"result-code\":1, \"result-msg\": \"调整失败\", \"data-map\": {}}";
    } else {
      double value_out = std::stod(value); // string转double
      // TODO: 调整图像的亮度
    }
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  }
  else if (cmd.type == "adjust_image_contrast")
  {
    std::string value = BufferParser::Instance()->FindValueByKey(cmd, "image-contrast");
    if (value == "") {
      return "{\"result-code\":1, \"result-msg\": \"调整失败\", \"data-map\": {}}";
    } else {
      double value_out = std::stod(value); // string转double
      // TODO: 调整图像的对比度
    }
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  }
  else if (cmd.type == "image_reset")
  {
    // TODO: 重置图像的亮度与对比度
    return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
  }
  return "{\"result-code\":1, \"result-msg\": \"调整失败\", \"data-map\": {}}";
}

// 恢复出厂设置
std::string panoramic_app::FactoryReset(Command &cmd)
{
  std::cout << "enter: " << __func__ << std::endl;
    // TODO: 恢复出厂设置
  return "{\"result-code\":0, \"result-msg\": \"操作成功\", \"data-map\": {}}";
}

//设置系统时间
std::string panoramic_app::SetDateTime(Command &cmd)
{
  std::cout << __func__ << " enter" << std::endl;
  std::string year = BufferParser::Instance()->FindValueByKey(cmd,"year");
  std::string month = BufferParser::Instance()->FindValueByKey(cmd,"month");
  std::string day = BufferParser::Instance()->FindValueByKey(cmd,"day");
  std::string  hour = BufferParser::Instance()->FindValueByKey(cmd,"hour");
  std::string  min = BufferParser::Instance()->FindValueByKey(cmd,"min");
  std::string  sec = BufferParser::Instance()->FindValueByKey(cmd,"sec");
  std::string shell_command = "timedatectl set-time \""+year+"-"+month+"-"+day+" "+hour+":"+min+":"+sec+"\""+" 2>&1"; //this way can change time without root

  char buf[256];
  memset(buf, 0, sizeof(buf));
  call_cmd(shell_command.data(),buf,sizeof(buf));

  
  if(strlen(buf)<1){
    return "{\"result-code\":0,\"result-msg\": \"operation successful\", \"data-map\": {}}";
  }
  else{
    buf[strlen(buf)-1]='\0';
    return std::string("{")+"\"result-code\":1,\"result-msg\": \""+buf+"\", \"data-map\": {}}";
  }
  
}

//查询存储卡信息,返回json格式
std::string panoramic_app::GetSDcardInfo(Command &cmd){
  std::cout << __func__ << " enter" << std::endl;
  #define SDCARD_FILENAME "/dev/sdd1"
  std::string shell_command = std::string("df -h ")+SDCARD_FILENAME+" 2>&1";
  std::string returnStr ="";
  
  FILE *fp = NULL;
  std::vector<char*> sd_info;

  fp=popen(shell_command.data(), "r");
  // std::cout << WIFEXITED(fp) << std::endl; //打印子进程状态(是否执行完毕)
 
  if (NULL==fp){
    pclose(fp);
    return "{\"result-code\":1,\"result-msg\": \"operation failed\", \"data-map\": {}}";
  }
  char buf[256];
  memset(buf, 0, sizeof(buf));
  while(fgets(buf,sizeof(buf),fp)!=0){
    std::cout << buf << std::endl; 
    if(strstr(buf,"df:")!=NULL){
      pclose(fp);
      return "{\"result-code\":1,\"result-msg\": \"operation failed,sdcard not find\", \"data-map\": {}}";
    }
    if (strstr(buf,SDCARD_FILENAME)!=NULL){
      char * sp_buf;
      sp_buf = strtok(buf," ");
      while(sp_buf){
        sd_info.push_back(sp_buf);
        sp_buf = strtok(NULL, " ");
      
      }
      pclose(fp);
      returnStr = std::string("{")+"\"result-code\":0,\"result-msg\": \"operation succesful\",\"data-map\":{\"total-size\":\""+sd_info[1]+"\",\"used-size\":\""+sd_info[2]+"\",\"left-size\":\""+sd_info[3]+"\"}}";
      return returnStr;

    }
  }
  
  

}
//格式化sd卡，目前采用删除文件实现
std::string panoramic_app::FormatSDcard(Command &cmd){
  //#define SDCARD_PATH "/media/chunyan/6631-3563"
  #define SDCARD_PATH "/home/chunyan/wang/code/360_huangshi/test_2020"
  if( access(SDCARD_PATH, 0) < 0 ){
    return "{\"result-code\":1,\"result-msg\": \"SDcard not find\", \"data-map\": {}}";
  }
  else{
    std::string shell_command = std::string("rm -rf ")+SDCARD_PATH+"/* 2>&1";
    char buf[256];
    memset(buf, 0, sizeof(buf));
    call_cmd(shell_command.data(), buf,sizeof(buf));
    if(strlen(buf)<1){
      return "{\"result-code\":0,\"result-msg\": \"operation successful\", \"data-map\": {\"total-size\":\"256g\",\"used-size\":\"0g\",\"left-size\":\"256g\"}}";
    }
    else{
      buf[strlen(buf)-1]='\0';
      return std::string("{")+"\"result-code\":1,\"result-msg\": \""+buf+"\", \"data-map\": {}}";
    }
  }
}

//修改密码 只是个接口，没填内容，比如旧密码如何存储，加密解密校验等等
std::string panoramic_app::ChangePassword(Command &cmd){
  std::cout << __func__ << " enter" << std::endl;
  std::string mode = BufferParser::Instance()->FindValueByKey(cmd,"code_attrib");
  std::string old_pwd = BufferParser::Instance()->FindValueByKey(cmd,"old_password");
  std::string new_pwd = BufferParser::Instance()->FindValueByKey(cmd,"new_password");
  std::string pwd_exist;
  if (mode=="user_mode"){
    //todo
  }
  else if(mode == "engineer_mode"){
    //todo
  }
  else {
    return "{\"result-code\":1,\"result-msg\": \"operation failed ,no such user mode\", \"data-map\": {}}";
  }
  if (old_pwd!=pwd_exist){
    return "{\"result-code\":1,\"result-msg\": \"operation failed ,password wrong\", \"data-map\": {}}";
  }
  else{
    if(old_pwd==new_pwd){
      return "{\"result-code\":1,\"result-msg\": \"operation failed ,new password is the same as old  \", \"data-map\": {}}";
    }
    else{
      pwd_exist=new_pwd;
      return "{\"result-code\":0,\"result-msg\": \"operation succesful  \", \"data-map\": {}}";
    }
  }

}
//显示本机信息
std::string panoramic_app::GetSystemInfo(Command &cmd){
  std::cout << __func__ << " enter" << std::endl;
  std::string hardware_id;
  std::string software_version;
  std::string return_str="";
  cv::FileStorage system_info;
  #define SYSTEM_INFO_PATH "/home/chunyan/wang/code/360_huangshi/panoramic_server/build/system_info.yml" 
  
  system_info.open(SYSTEM_INFO_PATH,cv::FileStorage::READ);
  if(!system_info.isOpened()){
    return "{\"result-code\":1,\"result-msg\": \"operation failed ,can not find system info \", \"data-map\": {}}";
  }
  
  system_info["hardware_id"] >> hardware_id;
  system_info["software_version"] >> software_version;
  system_info.release();
  
  return_str += "{\"result-code\":0,\"result-msg\": \"operation succesful\", \"data-map\": {";
  return_str += "\"hardware_id\": \""+hardware_id+"\",";
  return_str += "\"software_version\": \""+software_version+"\"}}";
  return return_str;
}


//用户日志 日志的结构为 时间 日志类型 具体内容，中间以空格分开 eg 20170102 参数调整 图像亮度调整
std::string panoramic_app::GetLogInfo(Command &cmd){
  std::cout << __func__ << "enter" << std::endl;
  #define LOG_INFO_PATH "/home/chunyan/wang/code/360_huangshi/panoramic_server/build/log_info.txt"
  std::string line;
  std::ifstream log_info (LOG_INFO_PATH);
  std::string return_str;
  int line_count= 0;
  std::string data_map = "\"data-map\": {\"log-info\": [";
  std::vector<std::string> log_content;
  if(log_info.is_open()){
    while (getline(log_info,line)){
      line_count++;
      std::stringstream ss (line);
      
      while(getline(ss, line, ' ')){
        log_content.push_back(line);
      }
      data_map+="{\"time\":\""+log_content[0]+"\",\"log-type\":\""+log_content[1]+"\",\"content\":\""+log_content[2]+"\"},";
    }
    log_info.close();
    if(data_map[data_map.length()-1] == ','){
      data_map.erase(data_map.end() - 1);
    }
    data_map+="],\"log-num\":\""+std::to_string(line_count)+"\"}";
    return_str = "{\"result-code\":0,\"result-msg\": \"operation succesful\", ";
    return_str+= data_map;
    return_str+="}";
    return return_str;
  }
  else
  {
    return "{\"result-code\":1,\"result-msg\": \"operation failed ,can not find log \", \"data-map\": {}}";
  }
  

}
panoramic_app *panoramic_app::Instance() {
  if (nullptr == p_instance) p_instance = new panoramic_app();
  return p_instance;
}

void panoramic_app::ReleaseInstance() { if (p_instance) delete p_instance; }
