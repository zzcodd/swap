#pragma once
#include <string>
#include <vector>
//#include <opencv2/opencv.hpp>
//#include <glog/logging.h>
#include "common_utils/include/string_util.h"
#include "common_utils/include/http_util.h"
#include "common_utils/include/common.h"

int CheckYmlHeader(const std::string &fn); //正常返回0，错误返回-1

std::string GetAbsolutePath(const std::string &relative_path,
                            const std::string &rt_path = "./");

/*
template<class T, bool CHECK_ERROR = 0>
T readFromFile(const std::string &fn, const std::string &name,
               T default_value = T()) {
  cv::FileStorage fs(GetAbsolutePath(fn), cv::FileStorage::READ);
  CHECK(fs.isOpened()) << fn;
  T res = default_value;

  if (CHECK_ERROR)
    CHECK(!fs[name].isNone()) << fn << " " << name;

  if (!fs[name].isNone())
    fs[name] >> res;
  fs.release();
  return res;
}
*/

typedef struct {
  std::string app_name;
  std::string client_name;
  int port;
  std::string method_name;
  std::string app_path;
  std::string stream_url;
  std::string record_path;
  std::string log_path;
} MainConfig;

int ParseConfig(std::string path, MainConfig &config);
