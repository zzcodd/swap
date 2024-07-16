#include "svm_app.h"
#include <iostream>
#include <jsoncpp/json/json.h>
#include "../config.h"
#include "svm_db.h"
#include "common.h"
#include "src/utils/log.h"

svm_app *svm_app::p_instance = nullptr;

std::string svm_app::Handle(Command &cmd)
{
  std::string result = "thank you call";

  HANDLE_CMD("login", Login);
  
  //HANDLE_CMD("get_vehicle_list", GetVehicleList);

  return result;
}

std::string svm_app::Login(Command &cmd)
{
  std::string username = BufferParser::Instance()->FindValueByKey(cmd,
      "username");
  std::string password = BufferParser::Instance()->FindValueByKey(cmd,
      "password");

  int rc = svm_db::Instance()->Login((char*)username.c_str(),
      (char*)password.c_str());
  std::string msg = "failure";

  Json::Value root;
  Json::Value data_map;

  if (rc >= 0) {
    msg = "success";
    root["role"] = rc;

    char *id_string = generate_random_string(16);
    rc = svm_db::Instance()->UpdateToken((char*)username.c_str(),
        id_string);

    std::string session_id = id_string;
    free(id_string);

    root["session_id"] = session_id;
    root["stream_url"] = "ws://svm.pingtai.cidiserver.com:41001";
  }
  root["code"] = rc;
  root["msg"]  = msg;
  Json::FastWriter writer;
  std::string returnStr = writer.write(root);
  return returnStr;
}

#if 0
std::string svm_app::GetVehicleList(Command &cmd)
{
  std::string project_id_str = BufferParser::Instance()->FindValueByKey(cmd,
      "project_id");
  int proj_id = -1;
  if (!project_id_str.empty())
    proj_id = atoi(project_id_str.c_str());
  std::vector<std::vector<std::string> > vehicle_list;
  int rc = svm_db::Instance()->FindAllVehicle(proj_id, vehicle_list);
  
  Json::Value root;
  Json::Value item, data_map;

  root["code"] = rc;
  root["msg"]  = "Success";
  for (int i = 0; i < vehicle_list.size(); i++) {
    item["name"] = vehicle_list[i][0];
    item["id"] = vehicle_list[i][1];
    data_map.append(item);
  }
  root["data"] = data_map;
  Json::FastWriter writer;
  std::string returnStr = writer.write(root);
  return returnStr;
}
#endif

svm_app *svm_app::Instance() {
  if (nullptr == p_instance) p_instance = new svm_app();
  return p_instance;
}

void svm_app::ReleaseInstance() { if (p_instance) delete p_instance; }
