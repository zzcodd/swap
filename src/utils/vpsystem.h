#pragma once
#include <iostream>
#include <mutex>

class vpSystem {

 public:
  static vpSystem *Instance(void);
  static void ReleaseInstance(void);
  int call_cmd(std::string cmd, std::string &out_buffer, int type);
 private:
  static vpSystem *p_instance;
  void *pChildpid = NULL;
  long vopen_max(void);
  FILE *vpopen(const char *cmdstring, const char *type);
  int vpclose(FILE *fp);
};
