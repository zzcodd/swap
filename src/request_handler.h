#pragma once

#include <string>
#include "buffer_parser.h"

class RequestHandler {
    public:
        static RequestHandler *Instance(void);
        static void ReleaseInstance(void);

        std::string Handle(Command &cmd);

    private:
        static RequestHandler *p_instance;
};

