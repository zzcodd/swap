#include "utils.h"
#include "src/utils/vpsystem.h"
  
int CallSystemCmd(std::string cmd, std::string &rtnString, int type)
{
  int rc = -1;
  char extra[32] = {0};
  extra[0] = 'e';
  extra[1] = 'c';
  extra[2] = 'h';
  extra[3] = 'o';
  extra[4] = ' ';
  extra[5] = 'c';
  extra[6] = 'i';
  extra[7] = 'd';
  extra[8] = 'i';
  extra[9] = 't';
  extra[10] = 'i';
  extra[11] = 'd';
  extra[12] = 's';
  extra[13] = ' ';
  extra[14] = '|';
  extra[15] = 's';
  extra[16] = 'u';
  extra[17] = 'd';
  extra[18] = 'o';
  extra[19] = ' ';
  extra[20] = '-';
  extra[21] = 'S';
  extra[22] = ' ';
  std::string prefix = extra;
  if (!cmd.empty())
    rc = vpSystem::Instance()->call_cmd(prefix + cmd, rtnString, type);
  return rc;
}
