#include "svm_db.h"
#include <string.h>
#include <iostream>
#include "db_api/include/MysqlAccess.h"
#include "src/utils/log.h"

#include <unordered_set>

svm_db *svm_db::p_instance = nullptr;


// Login
int svm_db::Login(const char *username, const char *passwd)
{
	char sql_string[256] = {0};
  std::vector<std::vector<std::string> > result;
  if (!username || strlen(username) < 1 || !passwd || strlen(passwd) < 1)
    return -1;

	sprintf(sql_string,
      "SELECT user_id,role FROM users WHERE username='%s' AND password_hash='%s'",
      username, passwd);
  result.clear();
  int rc = MysqlAccess::Instance()->QuerySQL(sql_string, result, NULL);
  if (rc != 0) return -2;
  if (result.size() > 0) {
    AINFO << __func__ << " success.";
    return atoi(result[0][1].c_str());
  }
  AINFO << __func__ << " error, sql " << sql_string ;
  return -3;
}

/*
int svm_db::UpdateToken(char *username, char *token)
{
	char sql_string[256] = {0};
  if (!username|| strlen(username) < 1 || !token|| strlen(token) < 1) 
    return -1;

  snprintf(sql_string, sizeof(sql_string),
      "UPDATE user SET access_token='%s', update_timestamp='%ld' WHERE username='%s'", token, time(NULL), username);
  int rc = MysqlAccess::Instance()->UpdateSQL(sql_string, NULL);
  if (rc != 0) {
    AINFO << __func__ << " error, sql " << sql_string << std::endl;
    return -2;
  }
  return 0;
}
*/


//token-based
int svm_db::UpdateToken(char *username, char *token)
{
	char sql_string[512] = {0};
  std::vector<std::vector<std::string>> result;
 
	sprintf(sql_string,
      "SELECT user_id FROM users WHERE username='%s'",username);
  int rc = MysqlAccess::Instance()->QuerySQL(sql_string, result, nullptr);
  if(rc !=0 || result.empty()) {
    AINFO << __func__ << " error , sql " << sql_string ;
    return -1;
  }

  int user_id = std::stoi(result[0][0]);

  if(token == nullptr) {
    AINFO << __func__ << " error, failed to generate token " ;
    return -1;
  }

  snprintf(sql_string, sizeof(sql_string),
      "INSERT INTO sessions (session_token, user_id, created_at, expires_at) VALUES ('%s', %d, NOW(), NOW() + INTERVAL 1 HOUR) "
      "ON DUPLICATE KEY UPDATE session_token='%s', created_at=NOW(), expires_at=NOW()+INTERVAL 1 HOUR",
      token, user_id, token);

  rc = MysqlAccess::Instance()->UpdateSQL(sql_string, nullptr);
  if (rc != 0) {
    AINFO << __func__ << " error, sql " << sql_string ;
    return -2;
  }
  return 0;
}

int svm_db::FindAllVehicle(int project_id,
    std::vector<std::vector<std::string> > &result)
{
  char sql_string[256] = {0};

  result.clear();
  snprintf(sql_string, sizeof(sql_string),
      "SELECT vehicle_info,device_id FROM `vehicle` WHERE project_id='%d'",
      project_id);
	return MysqlAccess::Instance()->QuerySQL(sql_string, result, NULL);
}

svm_db *svm_db::Instance() {
  if (nullptr == p_instance) p_instance = new svm_db();
  return p_instance;
}

void svm_db::ReleaseInstance() { if (p_instance) delete p_instance; }

//成功0 失败-1
int svm_db::Register(const char *username, const char *passwd_hash, const char *email) 
{
  char sql_string[256] = {0};
  int role = 2; //默认CLIENT_UNKNOWN
  sprintf(sql_string, 
      "INSERT INTO users (username, password_hash, email, role) VALUES ('%s', '%s', '%s', '%d')",
      username, passwd_hash, email, role);
  
  int rc = MysqlAccess::Instance()->UpdateSQL(sql_string, NULL);
  if(rc != 0) {
    AINFO << __func__ << "error, sql " << sql_string ;
    return -1;
  }
  AINFO << __func__ << "success.\n"; 
  return 0;
}

//成功0 失败-1
int svm_db::UpdatePassword(const char *username, const char *new_passwd_hash)
{
  char sql_string[256] = {0};
  sprintf(sql_string, "UPDATE users SET password_hash='%s' WHERE username='%s'",
      new_passwd_hash, username);
  
  int rc =MysqlAccess::Instance()->UpdateSQL(sql_string, nullptr);
  if(rc != 0) {
    AINFO << __func__ << " error sql " << sql_string ;
    return -1;
  }

  AINFO << "Password updated successfully for user: " << username;
  return 0;
}


bool svm_db::IsUsernameExist(const char *username)
{
  char sql_string[256] = {0};
  std::vector<std::vector<std::string>> result;

  sprintf(sql_string,
      "SELECT user_id FROM users WHERE username='%s'",username);
  int rc = MysqlAccess::Instance()->QuerySQL(sql_string, result ,nullptr);
  return (rc==0 && !result.empty());    
}

bool svm_db::IsEmailExist(const char *email)
{
  char sql_string[256] = {0};
  std::vector<std::vector<std::string>> result;

  sprintf(sql_string,
      "SELECT user_id FROM users WHERE email='%s'",email);
  int rc = MysqlAccess::Instance()->QuerySQL(sql_string, result ,nullptr);
  return (rc==0 && !result.empty());    
}

bool svm_db::IsPasswordComplex(const char *password, PasswordStrength strength) 
{
    // 最小长度要求
    std::string passwd = password;
    if (passwd.length() < 8) {
        return false;
    }

    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_special = false;

    std::unordered_set<char> special_chars = {
        '@', '$', '!', '%', '*', '?', '&', '.', '#', '-', '_', '+', '=', ':',
        ';', '{', '}', '[', ']', '|', '\\', '^', '~', '(', ')', '<', '>', ','
    };

    for (char ch : passwd) {
        if (std::islower(ch)) {
            has_lower = true;
        } else if (std::isupper(ch)) {
            has_upper = true;
        } else if (std::isdigit(ch)) {
            has_digit = true;
        } else if (special_chars.count(ch)) {
            has_special = true;
        }
    }

    switch (strength) {
      case LOW:
        return has_lower && has_digit;
      case MEDIUM:
        return has_lower && has_upper && has_digit;
      case HIGH:
        return has_lower && has_upper && has_digit && has_special;
      default:
        return false;  
    }
}

bool svm_db::ValidateSession(const char *token)
{
  char sql_string[256] = {0};
  std::vector<std::vector<std::string>> result;

  sprintf(sql_string,
      "SELECT user_id FROM sessions WHERE session_token='%s' AND expires_at > NOW()",token);
  
  int rc = MysqlAccess::Instance()-> QuerySQL(sql_string, result, nullptr);
  
  return (rc == 0 && !result.empty());
}

int svm_db::Logout(const char *token)
{
  char sql_string[256] = {0};
  sprintf(sql_string,
      "DELETE FROM sessions WHERE session_token='%s'",token);
  int rc = MysqlAccess::Instance()->UpdateSQL(sql_string, nullptr);

  if(rc != 0 ) {
    AINFO << __func__ << " error, sql " << sql_string << std::endl;
    return -1;
  }
  return 0;
}