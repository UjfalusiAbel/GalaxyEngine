#include "Sandbox.h"

Galaxy::Core::Application* Galaxy::Core::CreateApplication()
{
    auto app = new Sandbox();
    return app;
}

