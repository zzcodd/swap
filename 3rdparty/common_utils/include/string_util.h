#ifndef COMMON_UTILS_INCLUDE_STRING_UTIL_H
#define COMMON_UTILS_INCLUDE_STRING_UTIL_H
// Original Author: Albert Zhang<xhzzhang@yeah.net>
// Last Changed: 2021-02-28 14:08:09
#include <string>
#include <vector>

void str_trim(char **pp_str, int size);

void split_string(const std::string &source, int size,
    std::vector<std::string> &result, const std::string &split_symbol);

// need free result
char *format_string(char * src, int *length);

int StringToHex(char *str, unsigned char *out, unsigned int *outlen);

void HexToAscii(unsigned char *pHex, unsigned char *pAscii, int nLen);
#endif // COMMON_UTILS_INCLUDE_STRING_UTIL_H
