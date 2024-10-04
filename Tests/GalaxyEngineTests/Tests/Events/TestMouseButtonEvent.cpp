#include <Events/MouseEvent.hpp>
#include <catch2/catch_all.hpp>
#include <iostream>

namespace Galaxy
{
    namespace Testing
    {
        class MouseButtonEventFixture
        {
        protected:
            Galaxy::Events::MouseInfo mInfo;
            Galaxy::Events::MouseButtonEvent mEvent;
        public:
            MouseButtonEventFixture() :mInfo(Galaxy::Events::MouseCode::GLFW_MOUSE_BUTTON_1, Galaxy::Events::MouseAction::MouseButtonPressed, Galaxy::Math::Vector2D(1.0f, 1.0f)), mEvent(mInfo)
            {}
        };

        TEST_CASE_METHOD(MouseButtonEventFixture, "Constructor", "[MouseButtonEvent]")
        {

            REQUIRE(mEvent.GetMouseCode() == Galaxy::Events::MouseCode::GLFW_MOUSE_BUTTON_1);
            REQUIRE(mEvent.GetMouseAction() == Galaxy::Events::MouseAction::MouseButtonPressed);
            REQUIRE(mEvent.GetMousePosition() == Galaxy::Math::Vector2D(1.0f, 1.0f));
        }

        TEST_CASE_METHOD(MouseButtonEventFixture, "ToString", "[MouseButtonEvent]")
        {
            REQUIRE(mEvent.ToString() == "Mouse event occured with mouse code 0 with mouse action button pressed and with mouse position (x: 1 , y: 1)");
        }
    }
}