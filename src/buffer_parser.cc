#include "buffer_parser.h"
#include <iostream>

BufferParser *BufferParser::p_instance = nullptr;

int BufferParser::ParseMapedData(std::map<std::string,std::string> &data,
    Command &cmd)
{
  if (data.size() < 1)
    return -1;
  std::map<std::string,std::string>::iterator it;
  for (it = data.begin(); it != data.end(); ++it) {
    cmd.params.push_back(std::make_pair(it->first, it->second));
    if (it->first == CMD_TYPE_NAME)
      cmd.type = it->second;
  }
  return 0;
}

int BufferParser::ParseHttpGetData(char *buffer, int size, Command &cmd)
{
  cmd.type = "";
  cmd.params.clear();

  if (size < 1)
    return -1;

  get_http_default_param_list(buffer, size, cmd.params);
  cmd.type = BufferParser::Instance()->FindValueByKey(cmd, CMD_TYPE_NAME);
  return 0;
}

int BufferParser::ParseHttpPostData(char *buffer, int size, Command &cmd)
{
  if (size < 1)
    return -1;

  get_http_json_param_list(buffer, size, cmd.params);
  cmd.type = BufferParser::Instance()->FindValueByKey(cmd, CMD_TYPE_NAME);
  return 0;
}
        
std::string BufferParser::FindValueByKey(Command &cmd, std::string keyName)
{
  if (cmd.params.size() < 1)
    return "";
  for (int i = 0; i < cmd.params.size(); i++)
    if (cmd.params[i].first == keyName) return cmd.params[i].second;
  return "";
}

void BufferParser::CopyCommand(Command &to, Command &from)
{
  to.app_name = from.app_name;
  to.type = from.type;
  to.params.clear();
  for (int i = 0; i < from.params.size(); i++)
    to.params.push_back(std::make_pair(from.params[i].first,
          from.params[i].second));
}

BufferParser *BufferParser::Instance() {
  if (nullptr == p_instance) p_instance = new BufferParser();
  return p_instance;
}

void BufferParser::ReleaseInstance() {}
