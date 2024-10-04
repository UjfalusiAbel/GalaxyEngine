#include <catch2/reporters/catch_reporter_event_listener.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>
#include <catch2/catch_test_case_info.hpp>
#include <iostream>

class testRunListener : public Catch::EventListenerBase
{
public:
    using Catch::EventListenerBase::EventListenerBase;
    
    void testCaseStarting(Catch::TestCaseInfo const& testInfo ) override
    {
        std::cout << "Testcase: " << testInfo.name <<" running" << std::endl;
        std::cout.flush();
    }
};

CATCH_REGISTER_LISTENER(testRunListener)