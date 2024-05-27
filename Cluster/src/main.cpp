#include "Sandbox.h"

Galaxy::Application* Galaxy::CreateApplication()
{
    auto app = new Sandbox();
    return app;
}

