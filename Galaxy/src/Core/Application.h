#pragma once
#include <iostream>

int main(int argc, char* argv[]);

namespace Galaxy
{
    class Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();

    private:
        friend int ::main(int argc, char* argv[]);
    };

    Application* CreateApplication();

}