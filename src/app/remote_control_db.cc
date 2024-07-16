#include "remote_control_db.h"
#include "db_api/include/MysqlAccess.h"
//#include "common.h"
#include <string.h>
#include <iostream>
#include <common_utils/include/http_util.h>
#include "src/utils/log.h"

remote_control_db *remote_control_db::p_instance = nullptr;

int remote_control_db::Process(
      char *project_name,
      char *vehicle_type,
      char *vehicle_info,
      char *device_name,
      char *hw_sign,
      char *username,
      char *protocol,
      std::vector<std::string> &data)
{
  char sql_string[512] = {0};
  std::vector<std::vector<std::string> > result;
  bool is_found = false;
  char real_vehicle_info[64] = {0};
  char *default_option = "on";

  if (!project_name || strlen(project_name) < 1)
    project_name = "None";
  if (!vehicle_type || strlen(vehicle_type) < 1)
    vehicle_type = "None";
  if (!device_name || strlen(device_name) < 1)
    device_name = "None";
  if (!username || strlen(username) < 1)
    username = "None";
  if (!protocol || strlen(protocol) < 1)
    protocol = "None";
  if (!vehicle_info || strlen(vehicle_info) < 1)
    vehicle_info = "None";
  else {
    for (int i = 0; i < strlen(vehicle_info); i++)
      real_vehicle_info[i] = toupper(vehicle_info[i]);
    std::string decoded_info = UrlDecode(real_vehicle_info);
    memset(real_vehicle_info, 0x0, sizeof(real_vehicle_info));
    strcpy(real_vehicle_info, decoded_info.c_str());
    vehicle_info = real_vehicle_info;
  }
  std::string use_project_name = project_name;
  int use_port = 0;
  std::string use_option = default_option;
  snprintf(sql_string, sizeof(sql_string),
           "SELECT port FROM client WHERE hw_sign = '%s'",
           hw_sign);
  result.clear();
  int rc = MysqlAccess::Instance()->QuerySQL(sql_string, result, NULL);
  if (rc != 0 || !hw_sign || strlen(hw_sign) < 1) {
    AERROR << "db error(" << sql_string << "), use default value\n";
  } else {
    // INSERT
    if (result.empty()) {
      snprintf(sql_string, sizeof(sql_string), "SELECT MAX(port) FROM client");
      result.clear();
      MysqlAccess::Instance()->QuerySQL(sql_string, result, NULL);
      int max_port = 41120;
      max_port = stoi(result[0][0]);
      use_port = max_port + 1;
      snprintf(sql_string, sizeof(sql_string),
               "INSERT INTO client(hw_sign, port) VALUES "
               "('%s', '%d')", hw_sign, use_port);
      rc = MysqlAccess::Instance()->InsertSQL(sql_string, NULL);
      AINFO << __func__ << " insert sql:" << sql_string << std::endl;
    }
    else if(result.size() == 1)
      use_port = stoi(result[0][0]);
  }

  std::string section;
  section.append(use_project_name);
  section.append("_");
  section.append(vehicle_info);
  section.append("_");
  section.append(device_name);
  section.append("_");
  section.append(hw_sign);
  section.append("_");
  section.append(username);
  section.append("_");
  section.append(protocol);
  data.clear();
  // section
  data.push_back(section);
  // port
  data.push_back(std::to_string(use_port));
  // switch
  data.push_back(use_option);
  return rc;
}

int remote_control_db::Disconnect(void)
{
  MysqlAccess::Instance()->CloseConnect();
  return 0;
}

remote_control_db *remote_control_db::Instance() {
  if (nullptr == p_instance) p_instance = new remote_control_db();
  return p_instance;
}

void remote_control_db::ReleaseInstance() { if (p_instance) delete p_instance; }
