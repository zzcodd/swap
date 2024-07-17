/*
 * @Description: 
 * @Author: zy
 * @Date: 2024-06-18 15:48:44
 * @LastEditTime: 2024-07-17 09:05:58
 * @LastEditors: zy
 */
#include "base_db.h"
#include <jsoncpp/json/json.h>
#include "db_api/include/MysqlAccess.h"
#include "common_utils/include/file_util.h"
#include "src/utils/log.h"
#include "data_shadow/include/data_translate.h"
  
int base_db::Connect(char *config_file)
{
  char host[64] = {0};
  int port = -1;
  char username[32] = {0};
  char password[32] = {0};
  char db_name[32] = {0};

  long size = get_file_length(config_file);;
  char *json_data = (char*)malloc(size + 1);
  if (!json_data) return -1;
  int ret = read_file_context(config_file, json_data, size, "r");
  if (ret < 0) return ret;
 
  Json::Value root;
  Json::Reader reader;
  reader.parse(json_data, root);
  free(json_data);

  if (root["mysql_host"].empty()) return -1;
  strcpy(host, root["mysql_host"].asCString());
  port = root["mysql_port"].asInt();
  strcpy(username, root["mysql_username"].asCString());

  const char *enco_pass = root["mysql_password"].asCString();
  if (strlen(enco_pass) > 0) {
    char *orig_pass = data_decode((int*)&size, enco_pass, strlen(enco_pass));
    strcpy(password, orig_pass);
    free(orig_pass);
  }
  else strcpy(password, "");
  strcpy(db_name, root["mysql_db_name"].asCString());


  //log the connection information
  AINFO << "Attempting to connect to MySQL databases:";
  AINFO << "Host: " << host;
  AINFO << "Port: " << port;
  AINFO << "Username: " << username;
  AINFO << "Password: " << password;
  AINFO << "Database Name: " << db_name;

  MysqlAccess::Instance()->Configure(host, port, username, password, db_name);
  
  MysqlAccess::Instance()->CloseConnect();
  int rc = MysqlAccess::Instance()->OpenConnect();
  AINFO << __func__ << " user " << username << " connect state " << rc << "\n";
  if (!rc) is_connected = true;
  return rc;
}
  
int base_db::Disconnect(void)
{
  if (is_connected)
    MysqlAccess::Instance()->CloseConnect();
  return 0;
}
