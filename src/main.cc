/*
 * @Description: 
 * @Author: zy
 * @Date: 2024-06-18 15:48:44
 * @LastEditTime: 2024-06-19 15:20:54
 * @LastEditors: zy
 */
#include <stdio.h>
#include <string.h>
#include "hv_web_server.h"
//#include "web_server.h"
#include "app/base_db.h"
#include "config.h"
#include "src/utils/log.h"
#include "common_utils/include/log.h"
#include ".version.h"

#define CONFIG_FILE "./config.json"
#define MODULE_NAME "web_server"

//static WebServer web_server;
static HVWebServer web_server;
base_db db;
MainConfig config;

static void Initialize(char *file_path)
{
  db.Connect(file_path);
  web_server.Initialize();
}

static void Start(void)
{
  web_server.Start();
  web_server.Loop();
}

static void Stop(void)
{
  db.Disconnect();

  web_server.Stop();
  CLogger::Get().Shutdown();
}

static void Destory(void)
{
}

#ifdef WEB_SERVER_API
static void* WebServerHandler(void *param)
{
  char *file = (char*)param;
  ParseConfig(file, config);

  Initialize(file);

  Start();

  return NULL;
}

void WebServerActivate(const char *configFile)
{
  ACTIVATE_THREAD(WebServerHandler, (void*)configFile);
}
#else
int main(int ac, char **av)
{
  char *config_file = CONFIG_FILE;
  if (ac > 1)
    config_file = av[1];
  ParseConfig(config_file, config);

  //init_log(ac, av, (char*)GenerateLogDatePath(config.log_path).data(), 365*2,
  //    0);
  CLogger::Get().Init(GenerateLogDatePath("./log/"), MODULE_NAME);

  AINFO << MODULE_NAME << " version " << VERSION_CODE;
  AINFO << MODULE_NAME << " date " << VERSION_DATE;

  Initialize(config_file);

  Start();

  Stop();

  Destory();

  return 0;
}
#endif
