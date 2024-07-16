#ifndef COMMON_UTILS_INCLUDE_CURL_CLIENT_H
#define COMMON_UTILS_INCLUDE_CURL_CLIENT_H
// Original Author: Albert Zhang<xhzzhang@yeah.net>
// Last Changed: 2021-02-28 14:08:09
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

/**
 * @brief   curl client initialization
 *
 * @param   verbose   Verbose(1: enable, 0: disable)
 *
 * @retval  void
 */
void curl_client_init(int vebose);

/**
 * @brief   HTTP GET request
 *
 * @param   url         Full http link include params
 * @param   out_buf     A 2nd-pointer for result
 * @param   out_len     length of out_buf
 *
 * @retval  0           Success
 *          -1          Failure
 */
int curl_client_HTTP_GET(char *url, char **out_buf, int *out_len);

/**
 * @brief   HTTP POST request, params is json
 *
 * @param   url         The URL of HTTP server
 * @param   header_lsit The HTTP header list
 * @param   json_data   Point to a json text, if json_data is NULL, then use HTTP GET
 * @param   out_buf     A 2nd-pointer for result
 * @param   out_len     length of out_buf
 *
 * @retval  0           Success
 *          -1          Failure
 *          -2          Param is empty
 */
int curl_client_HTTP_POST_json(char *url,
    std::vector<std::string> &header_list, char *json_data, char **out_buf,
    int *out_len);

/**
 * @brief   HTTP POST request, params is key-value map
 *
 * @param   url         The URL of HTTP server
 * @param   header_lsit The HTTP header list
 * @param   map_list    The key-value list for param, it map_list is empty,then use HTTP GET
 * @param   out_buf     A 2nd-pointer for result
 * @param   out_len     length of out_buf
 *
 * @retval  0           Success
 *          -1          Failure
 */
int curl_client_HTTP_POST_keyvalue(char *url,
    std::vector<std::string> &header_list,
    std::map<std::string, std::string> &map_list, char **out_buf, int *out_len);

/**
 * @brief   HTTP GET request, save result to file
 *
 * @param   url         Full http link include params
 * @param   save_file   Full path for local filesystem
 *
 * @retval  0           Success
 *          -1          Failure
 *          -2          No more memory
 */
int curl_client_HTTP_GET_result_to_file(char *url, char *save_file);

/**
 * @brief   HTTP POST request, params is json, and save result to file
 *
 * @param   url         The URL of HTTP server
 * @param   header_lsit The HTTP header list
 * @param   json_data   Point to a json text, if json_data is NULL, then use HTTP GET
 * @param   save_file   Full path for local filesystem
 *
 * @retval  0           Success
 *          -1          Failure
 */
int curl_client_HTTP_POST_json_result_to_file(char *url,
    std::vector<std::string> &header_list,
    char *json_data, char *save_file);

/**
 * @brief   HTTP POST request, params is key-value map
 *
 * @param   url         The URL of HTTP server
 * @param   header_lsit The HTTP header list
 * @param   map_list    The key-value list for param
 * @param   save_file   Full path for local filesystem
 *
 * @retval  0           Success
 *          -1          Failure
 */
int curl_client_HTTP_POST_keyvalue_result_to_file(char *url,
    std::vector<std::string> &header_list,
    std::map<std::string, std::string> &map_list, char *save_file);

/**
 * @brief   Upload file
 *
 * @param   url         The URL of HTTP server
 * @param   header_lsit The HTTP header list
 * @param   map_list    The key-value list for param
 * @param   file_list   The key-value list for CURLFORM_FILE
 * @param   out_buf     A 2nd-pointer for result
 * @param   out_len     length of out_buf
 *
 * @retval  0           Success
 *          -1          Failure
 */
int curl_client_upload_file(char *url, std::vector<std::string> &header_list,
    std::map<std::string, std::string> &map_list,
    std::map<std::string, std::string> &file_list, char **out_buf,int *out_len);

/**
 * @brief   HTTP POST request, params is key-value map
 *
 * @param   url         The URL of HTTP server
 * @param   header_lsit The HTTP header list
 * @param   map_list    The key-value list for param
 * @param   file_list   The key-value list for CURLFORM_FILE
 * @param   save_file   Full path for local filesystem
 *
 * @retval  0           Success
 *          -1          Failure
 */
int curl_client_upload_file_result_to_file(char *url,
    std::vector<std::string> &header_list,
    std::map<std::string, std::string> &map_list,
    std::map<std::string, std::string> &file_list, char *save_file);

int curl_client_download_file(char *url, char *save_file);

/**
 * @brief   curl client destory
 *
 * @param   void
 *
 * @retval  void
 */
void curl_client_destory(void);

#endif //COMMON_UTILS_INCLUDE_CURL_CLIENT_H
