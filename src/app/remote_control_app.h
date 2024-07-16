#pragma once

#include <string>
#include <opencv2/core/core.hpp>
#include "base_app.h"
#include "../buffer_parser.h"

class remote_control_app : public base_app {
    public:
        static remote_control_app *Instance(void);
        static void ReleaseInstance(void);

        std::string Handle(Command &cmd);

        std::string Login(Command &cmd);

    private:
        static remote_control_app *p_instance;
};

