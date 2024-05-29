#pragma once

#include "Event.h"
#include "MouseCodes.h"
#include "../Math/Vector2D.h"
#include <string>
#include <sstream>

namespace Galaxy
{
    /// @brief Action types related to the mouse and its buttons
    enum MouseAction
    {
        MouseButtonPressed = 0,
        MouseButtonReleased = 1,
        MouseScrolled = 2,
        MouseMoved = 3,
        MouseDragged = 4
    };

    /// @brief Stores information about mouse button used, mouse action performed and current mouse position on screen
    struct MouseInfo
    {
        MouseCode code;
        MouseAction action;
        Vector2D mousePosition;
    };

    class MouseEvent : public Event
    {
    private:
        MouseInfo info;
    public:
        /// @brief Creates a MouseEvent with given MouseCode, Action and Vector2D mousePosition
        /// @param code  MouseCode, GLFW mousecode storing the mousebutton to which the action is related
        /// @param action Action, stores if the mousebutton was pressed or released, mouse was scrolled, moved or dragged
        /// @param mousePosition Vector2D, 2D position of mouse on screen with (0,0) beeing leftmost upper corner
        MouseEvent(MouseCode code, MouseAction action, Vector2D mousePosition);
        /// @brief Creates a MouseEvent with given info
        /// @param info Mouseinfo, stores information related to the mouse beeing the subject of the event
        MouseEvent(MouseInfo info);
        EVENT_TYPE_TO_STRING(Mouse);
        /// @brief Creates string information for debug purposes about data related to MouseEvent, showing MouseCode, MouseAction and Vector2D mousePosition
        /// @return information for logger, std::string
        std::string ToString() const override;
        /// @brief Gets code of MouseEvent
        /// @return mouse button acted on, MouseCode enum
        MouseCode GetMouseCode() const;
        /// @brief Gets ation of MouseEvent
        /// @return mouse action that occurred, MouseAction enum
        MouseAction GetMouseAction() const;
        /// @brief Gets position of MouseEvent
        /// @return mouse position on screen when event occurred, Vector2D object
        Vector2D GetMousePosition() const;
        ~MouseEvent() = default;
    };
}