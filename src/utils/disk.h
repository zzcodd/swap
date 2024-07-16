/*
 * @Author: zhang.hq zhang.hq@cidi.ai
 * @Date: 2023-11-08 14:16:01
 * @LastEditors: zhang.hq zhang.hq@cidi.ai
 * @LastEditTime: 2023-11-08 14:16:03
 * @FilePath: /ipu_web_server/src/utils/disk.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef SRC_UTILS_DISK_H
#define SRC_UTILS_DISK_H
//#pragma once
#include <string>
#include <opencv2/opencv.hpp>

#define SATA_DEV "ls -al /sys/block/sd* | grep -vE usb | awk '{print $9}'"
#define USB_DEV  "ls -al /sys/block/sd* | grep usb | awk '{print $9}'"
#define LOCAL_LOG_PATH       "/media/nvidia/log"
#define LOCAL_RECORD_PATH    "/media/nvidia/record"

long StrToInt(char *s);
bool makeDir(const std::string &sPathName);
bool removeFile(std::string fn);
bool removeDir(std::string fn);
bool moveFile(std::string src, std::string dst);
bool makeDir(const std::string &sPathName);
bool IsH264KeyFrame(cv::Mat encodeData);
bool checkPathExist(std::string fn);
std::vector<std::string> getFileList(std::string fn);
uint64 get_file_sz_KB(std::string fn);
bool GetDevPathAndSize(std::string devString, std::string &root_path_, long &size_, long &free_);
bool GetLogPathAndSize(std::string diskPath, std::string &root_path_, long &size_, long &free_);
bool GetRecordPathAndSize(std::string diskPath, std::string &root_path_, long &size_, long &free_);
bool getRecordDirs(std::string path, std::vector<std::string> &filenames);
void WriteFileNum(const std::string filename, uint64_t size);
uint64_t ReadFileNum(std::string filename);
uint64_t GetRecDirSize(std::string dirname, int duFlag);
bool getRecordDirs(std::string path,
                   std::deque<std::pair<std::string, uint64_t>> &dir_sz_tab,
                   uint64_t &total_sz);
std::string GetCurDate(std::string strMs);
std::string GetCurTime(std::string strMs);
std::string GetRecordDate(std::string recordName, uint32_t dateSize);
uint64_t GetFolderSize(std::string path);

#endif //SRC_UTILS_DISK_H
