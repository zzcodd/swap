#include "request_handler.h"
#include <iostream>
#include "app/panoramic_app.h"
#include "app/svm_app.h"
#include "app/remote_control_app.h"
#include "app/subway_app.h"
#include "app/im_notify_app.h"
#include "src/utils/log.h"

RequestHandler *RequestHandler::p_instance = nullptr;

std::string RequestHandler::Handle(Command &cmd)
{
#if 1
  AINFO << "---------incoming-------------";
  for (int i = 0; i < cmd.params.size(); i++)
    AINFO << "key " << cmd.params[i].first <<
      " value " << cmd.params[i].second;
#endif
  std::string result = "thank you call";
  if (cmd.params.size() < 1) return "param is empty";

  if (cmd.app_name == "panoramic")
    result = panoramic_app::Instance()->Handle(cmd);
  else if (cmd.app_name == "svm")
    result = svm_app::Instance()->Handle(cmd);
  else if (cmd.app_name == "remote_control")
    result = remote_control_app::Instance()->Handle(cmd);
  else if (cmd.app_name == "subway")
    result = subway_app::Instance()->Handle(cmd);
  else if (cmd.app_name == "im_notify")
    result = im_notify_app::Instance()->Handle(cmd);

  AINFO << "----------Rely------------\n" << result;
  return result;
}

RequestHandler *RequestHandler::Instance() {
  if (nullptr == p_instance) p_instance = new RequestHandler();
  return p_instance;
}

void RequestHandler::ReleaseInstance() {}
