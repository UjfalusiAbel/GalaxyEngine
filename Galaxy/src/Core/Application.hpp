#pragma once
#include <iostream>
#include <vector>
#include "Log.hpp"
#include "../Math/Vector2D.hpp"
#include "../Events/KeyboardEvent.hpp"
#include "../Events/MouseEvent.hpp"

int main(int argc, char* argv[]);

namespace Galaxy
{
    namespace Core
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

}