#define CATCH_CONFIG_MAIN
#include <Galaxy.hpp>
#include "catch.hpp"

class TestApp : public Galaxy::Core::Application
{
    void Run() override
    {
        
    }
};


Galaxy::Core::Application* Galaxy::Core::CreateApplication()
{
    auto app = new TestApp();
    return app;
}

