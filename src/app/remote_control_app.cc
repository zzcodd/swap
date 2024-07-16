#include "remote_control_app.h"
#include <iostream>
#include <jsoncpp/json/json.h>
#include "../config.h"
#include "remote_control_db.h"
#include "common.h"

remote_control_app *remote_control_app::p_instance = nullptr;

std::string remote_control_app::Handle(Command &cmd)
{
  std::string project_name = BufferParser::Instance()->FindValueByKey(cmd,"project_name");
  std::string vehicle_type = BufferParser::Instance()->FindValueByKey(cmd,"vehicle_type");
  std::string vehicle_info = BufferParser::Instance()->FindValueByKey(cmd,"vehicle_info");
  std::string device_name = BufferParser::Instance()->FindValueByKey(cmd,"device_name");
  std::string hw_sign = BufferParser::Instance()->FindValueByKey(cmd,"hw_sign");
  std::string username = BufferParser::Instance()->FindValueByKey(cmd,"username");
  std::string protocol = BufferParser::Instance()->FindValueByKey(cmd,"protocol");
  std::vector<std::string>  result;

  int rc = remote_control_db::Instance()->Process(
      (char*)project_name.c_str(),
      (char*)vehicle_type.c_str(),
      (char*)vehicle_info.c_str(),
      (char*)device_name.c_str(),
      (char*)hw_sign.c_str(),
      (char*)username.c_str(),
      (char*)protocol.c_str(),
      result);

  Json::Value root;
  Json::Value data_map;
  root["section"] = result[0];
  root["port"]  = atoi(result[1].c_str());
  root["switch"]  = result[2];
  Json::FastWriter writer;
  std::string returnStr = writer.write(root);
  return returnStr;
}

remote_control_app *remote_control_app::Instance() {
  if (nullptr == p_instance) p_instance = new remote_control_app();
  return p_instance;
}

void remote_control_app::ReleaseInstance() { if (p_instance) delete p_instance; }
