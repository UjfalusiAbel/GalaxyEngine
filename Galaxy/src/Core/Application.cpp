#include "Application.h"

namespace Galaxy
{
    Application::Application()
    {
        Galaxy::Logger* logger = Galaxy::Logger::GetInstance();
        logger->Init();
    }

    void Application::Run()
    {
    }

    Application::~Application()
    {
        std::cout << "App destroyed";
    }
}