#pragma once

#include <string>
#include <opencv2/core/core.hpp>
#include "base_app.h"
#include "../buffer_parser.h"

class im_notify_app : public base_app {
    public:
        static im_notify_app *Instance(void);
        static void ReleaseInstance(void);

        std::string Handle(Command &cmd);

        std::string Login(Command &cmd);

    private:
        static im_notify_app *p_instance;
};

