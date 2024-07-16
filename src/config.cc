#include "config.h"
#include <jsoncpp/json/json.h>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <regex>
#include "common_utils/include/file_util.h"

int CheckYmlHeader(const std::string &fn) {
  std::string str;
  std::ifstream inFile(fn);
  getline(inFile, str);//读取一行
  if (str.compare("%YAML:1.0") != 0) {
    inFile.close();
    return -1;
  }
  getline(inFile, str);//读取一行
  if (str.compare("---") != 0) {
    inFile.close();
    return -1;
  }
  inFile.close();
  return 0;
}

std::string GetAbsolutePath(const std::string &relative_path,
                            const std::string &prefix) {
  if (relative_path.empty()) {
    return prefix;
  }
  // If prefix is empty or relative_path is already absolute.
  if (prefix.empty() || relative_path.front() == '/') {
    return relative_path;
  }

  if (prefix.back() == '/') {
    return prefix + relative_path;
  }
  return prefix + "/" + relative_path;
}

int ParseConfig(std::string path, MainConfig &config)
{
  config.app_name = "";
  config.client_name = "";
  config.port = -1;
  config.method_name = "";
  config.app_path = "";
  config.stream_url = "";

  long size = get_file_length((char*)path.data());;
  char *data = (char*)malloc(size + 1);
  if (!data) return -1;
  int ret = read_file_context((char*)path.c_str(), data, size, "r");
  if (ret < 0) return ret;

  Json::Reader reader;
  Json::Value json_root;
  if (!reader.parse(data, json_root)) {
    free(data);
    return -1;
  }

  config.app_name = json_root["app_name"].asString();
  std::cout << "config app_name: " << config.app_name << std::endl;

  config.client_name = json_root["client_name"].asString();
  std::cout << "config client_name: " << config.client_name << std::endl;

  config.port = json_root["listen_port"].asInt();
  std::cout << "config port: " << config.port << std::endl;

  config.method_name = json_root["method_name"].asString();
  std::cout << "config method_name: " << config.method_name << std::endl;

  config.app_path = json_root["app_path"].asString();
  std::cout << "config app_path: " << config.app_path << std::endl;

  config.stream_url = json_root["stream_url"].asString();
  std::cout << "config stream_url: " << config.stream_url << std::endl;

  config.record_path = json_root["record_path"].asString();
  std::cout << "config record_path: " << config.record_path << std::endl;

  config.log_path = json_root["log_path"].asString();
  std::cout << "config log_path: " << config.log_path << std::endl;

end:
  free(data);
  return 0;
}

