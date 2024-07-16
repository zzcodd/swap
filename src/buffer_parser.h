#pragma once

#include <string>
#include <vector>
#include <map>
#include "config.h"

#define END_SYMBOL '\\'
#define CMD_TYPE_NAME "cmd_type"

// 协议：
// 	key=value&key=value+结束符
// 1. 第一个key建议作为指令类型，固定为"cmd-type"，比如"cmd-type=delete"
// 2. 第二个key建议为参数列表，其中的key可以为参数列表，其中里面的内容可以也用
//    '|'组成，比如"20120315.mp4|20120316.mp4"
// 3. 结束符号代表结束该指令
//
// 一个完整的指令解析成下面的数据
typedef struct {
  std::string app_name;
	std::string type;
  std::vector<std::pair<std::string, std::string> > params;
} Command;

class BufferParser {
    public:
        static BufferParser *Instance(void);
        static void ReleaseInstance(void);

        int ParseMapedData(std::map<std::string,std::string> &data,
            Command &cmd);

        int ParseHttpGetData(char *buffer, int size, Command &cmd);

        int ParseHttpPostData(char *buffer, int size, Command &cmd);

        std::string FindValueByKey(Command &cmd, std::string keyName);

        void CopyCommand(Command &to, Command &from);

    private:
        static BufferParser *p_instance;
};
