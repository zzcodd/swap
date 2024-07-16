#ifndef COMMON_UTILS_INCLUDE_HTTP_UTIL_H
#define COMMON_UTILS_INCLUDE_HTTP_UTIL_H
// Original Author: Albert Zhang<xhzzhang@yeah.net>
// Last Changed: 2021-02-28 14:08:09

#include <string>
#include <vector>

int get_http_default_param_list(std::string text, int size,
    std::vector<std::pair<std::string, std::string> > &params);

int get_http_json_param_list(std::string text, int size,
    std::vector<std::pair<std::string, std::string> > &params);

std::string UrlEncode(const std::string& str);

std::string UrlDecode(const std::string& str);

#endif //COMMON_UTILS_INCLUDE_HTTP_UTIL_H
