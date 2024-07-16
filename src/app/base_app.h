#pragma once
#include <string>
#include "../buffer_parser.h"

class base_app {
  public:

    std::string FileList(Command &cmd);

    std::string GetFileListPage(Command &cmd);

    std::string FileCopy(Command &cmd);

    std::string FileRemove(Command &cmd);

  private:
};
