#pragma once
#include <string>

class HVWebServer {
    public:
        void Initialize(void);
        int Start(void);
        void Stop(void);
        void Loop(void);

    private:

        int threads;
};
