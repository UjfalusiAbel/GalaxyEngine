#include "Application.h"

extern Galaxy::Application* Galaxy::CreateApplication();

int main(int argc, char* argv[])
{
    Galaxy::Application* app = Galaxy::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
