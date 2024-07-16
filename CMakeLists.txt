cmake_minimum_required(VERSION 2.8)

project(web_server)
#project(remote_control_server)
#project(im_notify_server)

if ("${cust_project}" STRGREATER "")
  project(${cust_project})
  message("use cust project name")
endif()

#option(USE_X86 "x86_64" ON)
option(USE_ARM "arm" ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -fPIC -pthread")

if ("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 3.0)
    message("cmake less then 3.0")
    # for cmake 2.x
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message("cmake more than 3.0")
    # for cmake 3.x
#    set(CMAKE_CXX_STANDARD 11)
#    set(CMAKE_CXX_STANDARD_REQUIRED ON)
	add_definitions(-g -O0 -Wall -std=c++11)
endif()

# openmp option
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

# optimization options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

# debug option
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)

# OpenCV package
FIND_PACKAGE(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/3rdparty)
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/spdlog/include)
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/libhv/include)
include_directories(/usr/local/include)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/common_utils/lib)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/db_api/lib)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/handy/lib)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/data_shadow/lib)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/spdlog/lib)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/libhv/lib)
link_directories(/usr/lib64/mysql)
link_directories(/usr/local/lib)

execute_process(COMMAND uname -m OUTPUT_VARIABLE CPU)
execute_process(COMMAND ${CMAKE_SOURCE_DIR}/eval_centos7.sh OUTPUT_VARIABLE CENTOS_VER)
if ("${CPU}" STREQUAL "aarch64\n")
  message("arch aarch64")
  set(common_utils_lib common_utils_arm)
  set(db_access_api_lib db_access_api_arm)
  set(handy_lib handy_arm)
  set(libhv_lib hv_arm)
  set(data_shadow_lib data_shadow_arm)
  set(spdlog_lib spdlog_arm)
elseif("${CENTOS_VER}" STREQUAL "\"7\"\n")
  message("arch centos7")
  set(common_utils_lib common_utils_centos7)
  set(db_access_api_lib db_access_api_centos7)
  set(handy_lib handy_centos7)
  set(libhv_lib hv_centos7)
  set(data_shadow_lib data_shadow_centos7)
  set(spdlog_lib spdlog_x86)
else()
  message("arch x86")
  set(common_utils_lib common_utils_x86)
  set(db_access_api_lib db_access_api_x86)
  set(handy_lib handy_x86)
  set(libhv_lib hv_x86)
  set(data_shadow_lib data_shadow_x86)
  set(spdlog_lib spdlog_x86)
endif()

file(GLOB _SRCS "src/*.cc")
file(GLOB _APPS "src/app/*.cc")
file(GLOB _UTILS "src/utils/*.cc")

add_executable(${PROJECT_NAME} ${_SRCS} ${_APPS} ${_LIBS} ${_UTILS})
target_link_libraries(${PROJECT_NAME} ${data_shadow_lib} ${common_utils_lib}
    ${handy_lib} ${libhv_lib} ${db_access_api_lib} ${spdlog_lib}
    mysqlclient crypto ssl jsoncpp ${OpenCV_LIBS} glog gflags)
