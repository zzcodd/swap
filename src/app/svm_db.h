/*
 * @Description: 
 * @Author: zy
 * @Date: 2024-06-18 15:48:44
 * @LastEditTime: 2024-08-20 14:22:01
 * @LastEditors: zy
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "base_db.h"

enum PasswordStrength {
  LOW = 0,      // 低：长度至少为8个字符，包含至少一个小写字母和一个数字。
  MEDIUM,   // 中：长度至少为8个字符，包含至少一个小写字母、一个大写字母和一个数字。
  HIGH      // 高：长度至少为8个字符，包含至少一个小写字母、一个大写字母、一个数字和一个特殊字符。
};

class svm_db : public base_db
{
	svm_db(){};
	virtual ~svm_db(){};

public:
	static svm_db* Instance(void);
	static void ReleaseInstance(void);

  int Login(const char *username, const char *passwd);
  
  int UpdateToken(char *data, char *username);

  int FindAllVehicle(int project_id, std::vector<std::vector<std::string> > &result);

  //新增方法实现功能的声明 成功0 失败-1
  int Register(const char *username, const char *passwd_hash);
  int UpdatePassword(const char *username, const char *new_passwd_hash);
  //退出会话 非注销
  int Logout(const char *token);

  int DeleteUser(const char *username);

  //显示已注册用户
  int GetAllUsers(std::vector<std::string> &users);
  // 获取用户身份
  int GetUserRole(const char *username, const char *passwd_hash);

  bool ValidateSession(const char *token);
  bool IsUsernameExist(const char *username);
  bool IsEmailExist(const char *email);
  bool IsPasswordComplex(const char *password, PasswordStrength strength = LOW);
private:
	static svm_db *p_instance;

};

