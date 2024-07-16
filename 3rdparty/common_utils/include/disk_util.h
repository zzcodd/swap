#ifndef COMMON_UTILS_INCLUDE_DISK_UTIL_H
#define COMMON_UTILS_INCLUDE_DISK_UTIL_H
//#pragma once
#include <string>

bool IsDiskOn(std::string dirName, unsigned char& usageRate,
    unsigned char& space);

#endif //COMMON_UTILS_INCLUDE_DISK_UTIL_H