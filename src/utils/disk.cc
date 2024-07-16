#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <cstdio>
#include "disk.h"
#include "vpsystem.h"
#include "common_utils/include/string_util.h"

bool IsH264KeyFrame(cv::Mat encodeData) {
  bool flag = false;
  if (encodeData.size().width > 0) {
    uchar *ptr = (uchar *) encodeData.data;
    if (0x67 == ptr[4] && 0x1 == ptr[3] && 0 == ptr[2] && 0 == ptr[2] && 0 == ptr[0]) {
      flag = true;
    }
  }
  return flag;
}

long StrToInt(const char *s) {
  long number = 0;
  if (s) {
    while (*s >= '0' && *s <= '9') {
      number = number * 10 + *s - '0';
      s++;
    }
  }
  return number;
}

bool GetDevPathAndSize(std::string devString, std::string &root_path_, long &size_, long &free_) {
  std::string cmdString;
  std::string rtnString;
  std::string dfString;
  dfString = "df | grep " + devString + "| grep -v loop | awk '{print $6\"|\"$2\"|\"$4}'";
  if (vpSystem::Instance()->call_cmd(dfString, rtnString, 0) <= 0) {
    return false;
  }
  std::vector<std::string> res;
  split_string(rtnString, rtnString.size(), res, "|");
  root_path_ = res[0];
  size_ = StrToInt(res[1].c_str());
  free_ = StrToInt(res[2].c_str());
  return true;
}

bool GetLogPathAndSize(std::string diskPath, std::string &root_path_, long &size_, long &free_) {
  bool ret = false;
  std::string cmdString;
  std::string rtnString;
  if (diskPath == "usrdisk") {
    cmdString = SATA_DEV;
    vpSystem::Instance()->call_cmd(cmdString, rtnString, 0);
    if (0 == rtnString.compare(0, 12, "/sys/block/sd", 0, 12)) {
      std::string devString = rtnString.substr(11, 3); //sdx
      ret = GetDevPathAndSize("/dev/" + devString + "1", root_path_, size_,
                              free_);
    }
  } else if (diskPath == "internaldisk") {
    ret = GetDevPathAndSize("/dev/nvme0n1p1", root_path_, size_, free_);
  } else {
    char path[128] = {0};
    int size = readlink(LOCAL_LOG_PATH, path, sizeof(path));
    if (diskPath == LOCAL_LOG_PATH && size > 0) {
      size = strlen(path);
      if ('/' == path[size - 1])
        path[size - 1] = '\0';
      char *name = strrchr(path, '/');
      if (name) name += 1;
      else name = path;
      ret = GetDevPathAndSize(name, root_path_, size_, free_);
    }
    else
      ret = GetDevPathAndSize(diskPath, root_path_, size_, free_);
  }
  return ret;
}

bool GetRecordPathAndSize(std::string diskPath, std::string &root_path_, long &size_, long &free_) {
  bool ret = false;
  std::string cmdString;
  std::string rtnString;
  if (diskPath == "usrdisk") {
    cmdString = SATA_DEV;
    vpSystem::Instance()->call_cmd(cmdString, rtnString, 0);
    if (0 == rtnString.compare(0, 12, "/sys/block/sd", 0, 12)) {
      std::string devString = rtnString.substr(11, 3); //sdx
      //std::cout << "hdd dev is " << devString<<"\n";
      ret = GetDevPathAndSize("/dev/" + devString + "2", root_path_, size_,
                              free_);
    }
  } else if (diskPath == "internaldisk") {
    ret = GetDevPathAndSize("/dev/nvme0n1p2", root_path_, size_, free_);
  } else if (diskPath == "usbdisk") {
    cmdString = USB_DEV;
    vpSystem::Instance()->call_cmd(cmdString, rtnString, 0);
    if (0 == rtnString.compare(0, 12, "/sys/block/sd", 0, 12)) {
      std::string devString = rtnString.substr(11, 3); //sdx
      ret = GetDevPathAndSize("/dev/" + devString, root_path_, size_, free_);
    }
  } else {
    char path[128] = {0};
    int size = readlink(LOCAL_RECORD_PATH, path, sizeof(path));
    if (diskPath == LOCAL_RECORD_PATH && size > 0) {
      size = strlen(path);
      if ('/' == path[size - 1])
        path[size - 1] = '\0';
      char *name = strrchr(path, '/');
      if (name) name += 1;
      else name = path;
      ret = GetDevPathAndSize(name, root_path_, size_, free_);
    }
    else
      ret = GetDevPathAndSize(diskPath, root_path_, size_, free_);
  }
  return ret;
}

uint64 get_file_sz_KB(std::string fn) {
  if (!fn.length())
    return 0;
  struct stat stat_buf;
  int rc = stat(fn.c_str(), &stat_buf);
  if (rc != 0)
    return 0;
  return stat_buf.st_size/1024;
}

bool moveFile(std::string src, std::string dst) {
  return std::rename(src.c_str(), dst.c_str()) == 0;
}

bool removeFile(std::string fn) {
  return std::remove(fn.c_str()) == 0;
}

bool removeDir(std::string fn) {
  std::string cmdString;
  std::string rtnString;
  cmdString = "rm -rf " + fn;
  return vpSystem::Instance()->call_cmd(cmdString, rtnString, 1) >= 0;
}

bool makeDir(const std::string &sPathName) {
  bool flag = true;
  if (0 != access(sPathName.c_str(), F_OK)) {
    char DirName[256];
    strcpy(DirName, sPathName.c_str());
    int i, len = strlen(DirName);
    if (DirName[len - 1] != '/') strcat(DirName, "/");

    len = strlen(DirName);

    for (i = 1; i < len; i++) {
      if (flag && DirName[i] == '/') {
        DirName[i] = 0;
        if ((access(DirName, F_OK) != 0) && (mkdir(DirName, 0755) == -1)) {
          perror("mkdir error");
          flag = false;
        }
        DirName[i] = '/';
      }
    }
  }
	return flag;
}

bool checkPathExist(std::string fn) {
  if (0 == access(fn.c_str(), 0)) {
    return true;
  } else {
    return false;
  }
}

bool getVecDIR(std::string path,std::vector<std::string> &vecDirNames){
  DIR *pDir = NULL;
  struct dirent* ptr = NULL;

  if (!(pDir = opendir(path.c_str()))) {
    return false;
  }

  while ((ptr = readdir(pDir)) != 0) {
    if (ptr->d_type != DT_DIR) {
      removeFile(path + ptr->d_name);
    }
    if (!strstr(ptr->d_name, ".")) {
      if (strcmp(ptr->d_name, "19700000") < 0 ||
          strcmp(ptr->d_name, "21000000") > 0) {
        removeDir(path + ptr->d_name);
      }
      else {
        vecDirNames.push_back(ptr->d_name);
      }
    }
  }
  closedir(pDir);

  sort(vecDirNames.begin(), vecDirNames.end());

  return true;
}

bool getRecordDirs(std::string path, 
                   std::deque<std::pair<std::string, uint64_t>> &dir_sz_tab,
                   uint64_t &total_sz) {
  bool flag = true;
  std::vector<std::string> vecDirNames;
  if(getVecDIR(path, vecDirNames)){
    std::string fileName;
    uint64_t fileSize;
    for (size_t i = 0; i < vecDirNames.size(); i ++){
      fileName = path + vecDirNames[i];
      if(i == vecDirNames.size() - 1) {
        fileSize = GetRecDirSize(fileName, 1);//最近的目录重新计算大小
      }
      else {
        fileSize = GetRecDirSize(fileName, 0);
      }
      
      dir_sz_tab.push_back({fileName, fileSize});
      total_sz += fileSize;
    }

    if (dir_sz_tab.empty()) {
      flag = false;
    }
  }

  return flag;
}

void WriteFileNum(const std::string filename, uint64_t size) {
  std::ofstream out_file(filename.c_str(), std::ios::trunc);
  out_file << size;
  out_file.flush();
  out_file.close();
}

uint64_t ReadFileNum(std::string filename) {
  uint64_t rtnNum = 0;
  std::ifstream in_file(filename.c_str());
  in_file >> rtnNum;
  in_file.close();
  return rtnNum;
}

uint64_t GetRecDirSize(std::string dirname, int duFlag) {
  uint64_t size = 0;
  std::string cmdString;
  cmdString = "du --max-depth=0 " + dirname + " | awk '{print $1}'";
  std::string rtnString;
  if (0 == access(dirname.c_str(), 0) || 1 == duFlag) {
    size = ReadFileNum(dirname);
  }
  if (0 == size) {
    if (vpSystem::Instance()->call_cmd(cmdString, rtnString, 0) > 0) {
      size = StrToInt(rtnString.c_str());
      WriteFileNum(dirname + "/size.dat", size);
      //std::cout << dirname << "   "<<size <<"   "<<rtnString<< "\n";
    }
  }
  return size; //Kb
}

std::string GetCurDate(std::string strMs) {
  std::string strDate = strMs;
  strDate.erase(8);
  return strDate;
}

std::string GetCurTime(std::string strMs) {
  std::string strTime = strMs;
  strTime.erase(14);
  strTime.erase(0, 8);
  return strTime;
}

std::string GetRecordDate(std::string recordName, uint32_t dateSize) {
  std::string strDate = recordName;
  strDate = strDate.substr(0, dateSize);
  return strDate;
}

uint64_t GetFolderSize(std::string path)
{
  std::string cmdString, rtnString;
  cmdString = "du --max-depth=0 " + path + " | awk '{print $1}'";
  if (vpSystem::Instance()->call_cmd(cmdString, rtnString, 0) >= 0)
    return atol(rtnString.c_str());
  return -1;
}
