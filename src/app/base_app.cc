#include <iostream>
#include <jsoncpp/json/json.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "base_app.h"
#include "src/utils/log.h"

//#define RECORD_ROOT_DIR "/home/cidi/ipu_android_app/webPage/data/record/"
#define RECORD_ROOT_DIR "/home/xhz/Projects/ips/output/webgui/record/"
#define URL_ROOT_DIR    ""
#define PATH_NUM        4
#define RECORD_TYPE_NUM 3
#define RECORD_PER_PAGE 20

std::string base_app::FileList(Command &cmd)
{
  Json::StyledWriter writer;
  Json::Value root;
  Json::Value data_map, direct_info;
  std::string path[PATH_NUM] = {"full/pano/","full/cameras/","key/pano/","key/cameras/"};
  std::string recordType[RECORD_TYPE_NUM] = {"avi","mp4","mpeg"};
  std::string urlRootPath = URL_ROOT_DIR;
  int  recordNum = 0;
  char retBuff[2048] = {0};

  DIR           *dir = NULL;
  struct dirent *ptr = NULL;
  std::cout << __func__ << " enter" << std::endl;

  if( access(RECORD_ROOT_DIR, 0) < 0 )
  {
    root["result_code"] = 1;
    root["result_msg"] = "SD卡为空或者发生错误";
  }
  else
  {
    root["result_code"] = 0;
    root["result_msg"] = "获取录像信息成功";

    for( int i = 0; i < PATH_NUM; i++ )
    {
      std::string dirPath = RECORD_ROOT_DIR+path[i];
      direct_info["dir_path"] = dirPath;
      //获得.avi .mp4 .mpg的总个数
      std::string cmd = "ls ";//ls后面需要有空格
      for( int j = 0; j < RECORD_TYPE_NUM; j++ )
      {
        cmd += dirPath +"*."+recordType[j] + " ";
      }
      cmd += "| wc -w";
      memset( retBuff, 0, 2048 );
      call_cmd(cmd.data(), retBuff, 2048);
      recordNum = std::atoi(retBuff);//转换一遍，去掉回车

      Json::Value record_info;
      direct_info["record_num"] = std::to_string(recordNum);
      direct_info["record_info"] = record_info;

      dir = NULL;
      dir = opendir(dirPath.data()); //open the dir
      if(dir)
      {
        while((ptr = readdir(dir)) != NULL) //read the list of this dir
        {
          for( int j = 0; j < RECORD_TYPE_NUM; j++ )
          {
            if( strstr(ptr->d_name, recordType[j].data()) )//查找所有的录像文件
            {
              std::string strName = ptr->d_name;
              record_info["record_name"] = strName;
              record_info["record_url"] = urlRootPath + path[i] + ptr->d_name;
              std::string jpeg_url = urlRootPath + path[i] + ptr->d_name;
              jpeg_url.erase(jpeg_url.end() - recordType[j].length(), jpeg_url.end());//删除最后后缀，替换为jpeg
              jpeg_url += "jpeg";
              record_info["jpeg_url"] = jpeg_url;
              direct_info["record_info"].append(record_info);
            }
          }
        }
        closedir(dir);
      }
      data_map["direct_info"].append(direct_info);
    }
  }
  root["data_map"] = data_map;
  std::string result = writer.write(root);
  return result;
}

static int filter_fn(const struct dirent * ent)
{
  if( strstr(ent->d_name, "avi") || strstr(ent->d_name, "mp4") || strstr(ent->d_name, "mpeg") )//查找所有的录像文件
  {
    return 1;
  }
  return 0;
}

std::string base_app::GetFileListPage(Command &cmd)
{
  std::cout << __func__ << " enter" << std::endl;

  std::string pageNo = BufferParser::Instance()->FindValueByKey(cmd,"page_no");
  std::string dirName = BufferParser::Instance()->FindValueByKey(cmd,"dir_name");
  int ipageNo = atoi(pageNo.c_str());

  Json::StyledWriter writer;
  Json::Value root;
  Json::Value data_map, record_info;
  std::string recordType[RECORD_TYPE_NUM] = {"avi","mp4","mpeg"};
  std::string urlRootPath = URL_ROOT_DIR;
  int  recordNum = 0;
  char retBuff[2048] = {0};
  int  count = 0;

  struct dirent **namelist;

  if( access(RECORD_ROOT_DIR, 0) < 0 )
  {
    root["result_code"] = 1;
    root["result_msg"] = "SD卡为空或者发生错误";
  }
  else if(ipageNo < 1)
  {
    root["result_code"] = 1;
    root["result_msg"] = "分页序号错误";
  }
  else
  {
    root["result_code"] = 0;
    root["result_msg"] = "获取录像信息成功";
    std::string dirPath = RECORD_ROOT_DIR+dirName;
    recordNum = scandir(dirPath.data(),&namelist,filter_fn,alphasort);//转换一遍，去掉回车
    if( recordNum < 0 )
    {
      recordNum = 0;
    }
    data_map["all_record_num"] = std::to_string(recordNum);
    data_map["all_page_num"] = std::to_string((recordNum+RECORD_PER_PAGE-1)/RECORD_PER_PAGE);
    data_map["page_no"] = pageNo;

    if( ipageNo <= recordNum/RECORD_PER_PAGE)
    {
      data_map["page_record_num"] = std::to_string(RECORD_PER_PAGE);
    }
    else
    {
      data_map["page_record_num"] = std::to_string(recordNum%RECORD_PER_PAGE);
    }

    data_map["record_info"] = record_info;
    for(int i = (ipageNo-1)*RECORD_PER_PAGE; i < recordNum; i++)
    {
      count++;
      if( count > RECORD_PER_PAGE )
      {
        break;
      }

      std::string strName = namelist[i]->d_name;
      record_info["record_name"] = strName;
      record_info["record_url"] = urlRootPath + dirName + namelist[i]->d_name;
      std::string jpeg_url = urlRootPath + dirName + namelist[i]->d_name;
      if(strstr(namelist[i]->d_name, recordType[2].data()) )
      {
        jpeg_url.erase(jpeg_url.end() - 4, jpeg_url.end());//删除最后后缀，替换为jpeg
      }else
      {
        jpeg_url.erase(jpeg_url.end() - 3, jpeg_url.end());
      }
      jpeg_url += "jpeg";
      record_info["jpeg_url"] = jpeg_url;
      data_map["record_info"].append(record_info);
    }
    if( recordNum > 0)
    {
      for(int i = 0; i < recordNum; i++)
      {
        free(namelist[i]);
      }
      free(namelist);
    }
    root["data_map"] = data_map;
  }
  std::string result = writer.write(root);
  return result;
}

std::string base_app::FileCopy(Command &cmd)
{
  std::cout << __func__ << "enter" << std::endl;
  return "";
}

std::string base_app::FileRemove(Command &cmd)
{
  std::cout << __func__ << " enter" << std::endl;
  std::string value = BufferParser::Instance()->FindValueByKey(cmd,"file_path");
  std::vector<std::string> name_list;
  std::vector<std::string> path_split;
  name_list.clear();
  path_split.clear();
  std::string text;
  split_string(value, value.size(), name_list, "|");
  for (int i = 0; i < name_list.size(); i++) {
    std::string path = name_list[i];
    std::cout << " file_path:" << path.c_str() << std::endl;
    split_string(path, path.size(), path_split, "/");
    std::string file_name = path_split[path_split.size()-1];
    AERROR << __func__ << "-文件操作-删除录像文件" << file_name;
    remove(path.c_str());
  }
  Json::StyledWriter writer;
  Json::Value root;
  Json::Value data_map;
  root["data_map"] = data_map;
  root["result_code"] = 0;
  root["result_msg"] = "删除录像成功";
  std::string result = writer.write(root);
  return result;
}
