#include "Application.h"

namespace Galaxy
{
    Application::Application()
    {

    }

    void Application::Run()
    {
        std::cout << "Engine running\n";
    }

    Application::~Application()
    {
        std::cout << "App destroyed";
    }
}