#include "im_notify_app.h"
#include <iostream>
#include <jsoncpp/json/json.h>
#include "common.h"

im_notify_app *im_notify_app::p_instance = nullptr;
extern MainConfig config;

std::string im_notify_app::Handle(Command &cmd)
{
  char buf[1024] = {0};
  std::string cmd_type = BufferParser::Instance()->FindValueByKey(cmd,
      "cmd_type");
  std::string device_id = BufferParser::Instance()->FindValueByKey(cmd,
      "device_id");
  std::string round = BufferParser::Instance()->FindValueByKey(cmd, "round");
  std::string msg = BufferParser::Instance()->FindValueByKey(cmd, "msg");
  if (config.client_name == "svm")
    sprintf(buf, "./notify_svm.sh %s %s %s", device_id.c_str(),
        round.c_str(), msg.c_str());
  else if (config.client_name == "subway")
    sprintf(buf, "./notify_subway.sh %s %s %s", device_id.c_str(),
        round.c_str(), msg.c_str());
  system(buf);
  return "send ok";
}

im_notify_app *im_notify_app::Instance() {
  if (nullptr == p_instance) p_instance = new im_notify_app();
  return p_instance;
}

void im_notify_app::ReleaseInstance() { if (p_instance) delete p_instance; }
