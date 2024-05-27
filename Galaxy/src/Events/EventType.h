#pragma once

#include "../Core/Utils.h"

namespace Galaxy
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