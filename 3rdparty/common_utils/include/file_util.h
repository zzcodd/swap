#ifndef COMMON_UTILS_INCLUDE_FILE_UTIL_H
#define COMMON_UTILS_INCLUDE_FILE_UTIL_H
// Original Author: Albert Zhang<xhzzhang@yeah.net>
// Last Changed: 2023-01-18 11:00:30

/*
 * @brief     Get file data
 *
 * @param
 *  path      real file path
 *  out_data  real path
 *  out_size  length of out_data
 *  mode      "r" or "rb"
 *
 * @return    >=0 success
 *           -1 input param error
 *           -2 file not exist
 */
int read_file_context(char *path, char *out_data, long size, char *mode);

/*
 * @brief     Save data to file
 *
 * @param
 *  path      full path
 *  buffer    buffer
 *  size      length of buffer
 *  mode      "a" or "w"
 *
 * @return    0 success
 *           -1 failure
 */
int write_file_context(char *path, unsigned char *buffer, int size,
    char *mode);

/*
 * @param     Get file length
 *
 * path       full path
 *
 * @return    >=0 real size
 *            -1 file not exist
 */
long get_file_length(char *path);

#endif //COMMON_UTILS_INCLUDE_FILE_UTIL_H
