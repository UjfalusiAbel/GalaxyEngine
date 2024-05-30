#pragma once
#include <iostream>
#include <vector>
#include "Log.h"
#include "../Math/Vector2D.h"
#include "../Events/KeyboardEvent.h"
#include "../Events/MouseEvent.h"

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