#ifndef COMMON_UTILS_INCLUDE_PTR_UTIL_H
#define COMMON_UTILS_INCLUDE_PTR_UTIL_H
// Author: Albert Zhang<xhzzhang@yeah.net>
//#pragma once

/**
 * memset()
 */
#define PTR_BZERO(x, size) do { \
    if (x) memset(x, 0x0, size); \
} while (0)

/**
 * malloc() and memset()
 */
#define PTR_MALLOC(x, type, size) do { \
    x = (type*)malloc(size); \
    PTR_BZERO(x, size); \
} while (0)

/**
 * realloc() and memset()
 */
#define PTR_REALLOC(x, type, size) do { \
    x = (type*)realloc(x, size); \
    PTR_BZERO(x, size); \
} while (0)

/**
 * free()
 */
#define PTR_FREE(x) do { \
    if (x) { \
        free(x); x = NULL; \
    } \
} while (0)

/**
 * new and memset()
 */
#define PTR_NEW(x, type, size) do { \
    x = new type[size]; \
    PTR_BZERO(x, size); \
} while (0)

/**
 * delete
 */
#define PTR_DELETE(x) do { \
    if (x) { \
        delete[] x; x = NULL; \
    } \
} while (0)

#endif // COMMON_UTILS_INCLUDE_PTR_UTIL_H
