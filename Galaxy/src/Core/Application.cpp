#include "Application.hpp"

namespace Galaxy
{
    namespace Core
    {
        Application::Application()
        {
            Logger* logger = Logger::GetInstance();
            logger->Init();
            Math::Vector2D vec(-3,2);
            GX_CORE_TRACE(vec.ToString());
        }

        void Application::Run()
        {
        }

        Application::~Application()
        {
            std::cout << "App destroyed";
        }
    }
}