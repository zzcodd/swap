#pragma once

/**
 * @brief   Encode secret data(i.e password) to serial text.
 *
 * @param   size        Length of output data
 *          src         source text
 *          count       length of source text
 *
 * @retval  A pointer of output data, need free it after use.
 */
char* data_encode(int *size, const char *src, int count);

/**
 * @brief   Recover secret data(i.e password) from serial text.
 *
 * @param   size        Length of output data
 *          src         source text
 *          count       length of source text
 *
 * @retval  A pointer of output data, need free it after use.
 */
char* data_decode(int *size, const char *src, int count);
