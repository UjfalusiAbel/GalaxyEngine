#include "Application.hpp"

extern Galaxy::Core::Application* Galaxy::Core::CreateApplication();

int main(int argc, char* argv[])
{
    Galaxy::Core::Application* app = Galaxy::Core::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
