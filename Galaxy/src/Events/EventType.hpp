#pragma once

#include "../Core/Utils.hpp"

namespace Galaxy
{
    namespace Events
    {
        enum class EventType
        {
            None = 0,
            KeyEvent = 1,
            MouseEvent = 2,
            WindowEvent = 3,
            //WindowResize,
            //WindowClose,
            //WindowBringForward,
            //WindowSendBackward,
            //WindowMove, 
            AppEvent = 4
            //AppUpdate,
            //AppRender,


        };
    }
}