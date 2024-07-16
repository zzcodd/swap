#pragma once

#include <string>
#include <opencv2/core/core.hpp>
#include "base_app.h"
#include "../buffer_parser.h"

class svm_app : public base_app {
    public:
        static svm_app *Instance(void);
        static void ReleaseInstance(void);

        std::string Handle(Command &cmd);

        std::string Login(Command &cmd);

        //std::string GetVehicleList(Command &cmd);

    private:
        static svm_app *p_instance;
};

