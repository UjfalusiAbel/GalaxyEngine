#pragma once

#include "../Core/Utils.hpp"

namespace Galaxy
{
    namespace Events
    {
        enum class EventType
        {
            None = 0,

            WindowResize,
            WindowClose,
            WindowBringForward,
            WindowSendBackward,
            WindowMove,

            AppUpdate,
            AppRender,

            KeyPressed,
            KeyReleased,

            MouseButtonDown,
            MouseButtonUp,
            MouseDragged,
            MouseScrolled
        };
    }
}