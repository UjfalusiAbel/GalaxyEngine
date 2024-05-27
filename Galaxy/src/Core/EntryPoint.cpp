#include "Application.h"
#include "Log.h"
#include "Utils.h"

extern Galaxy::Application* Galaxy::CreateApplication();

int main(int argc, char* argv[])
{
    Galaxy::Logger* logger = Galaxy::Logger::GetInstance();
    logger->Init();

    Galaxy::Application* app = Galaxy::CreateApplication();
    app->Run();

    delete logger;
    delete app;
    return 0;
}
