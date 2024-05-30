#pragma once

#include "Event.h"
#include "MouseCodes.h"
#include "../Math/Vector2D.h"
#include <string>
#include <sstream>
#include <exception>
#include "../Core/Utils.h"

namespace Galaxy
{
    class MouseEvent;
    class MouseButtonEvent;
    
    /// @brief Action types related to the mouse and its buttons
    enum MouseAction
    {
        MouseButtonPressed = 0,
        MouseButtonReleased = 1,
        MouseScrolled = 2,
        MouseMoved = 3,
        MouseDragged = 4
    };

    /// @brief Stores information about mouse button used and mouse action performed. Base class for other mouseinfo classes
    class MouseInfo
    {
        friend MouseEvent;
    protected:
        MouseCode code;
        MouseAction action;
    public:
        MouseInfo() = default;
        /// @brief Creates a MouseInfo with given MouseCode, Action and Vector2D mousePosition
        /// @param code MouseCode, GLFW mousecode storing the mousebutton to which the action is related
        /// @param action Action, stores if the mousebutton was pressed or released, scrolled, moved, dragged
        MouseInfo(MouseCode code, MouseAction action);
        virtual ~MouseInfo() = default;
    };

    /// @brief Stores information about mouse button used, mouse action performed and current mouse position on screen. Used in MouseButtonEvent
    class MouseButtonInfo :public MouseInfo
    {
        friend MouseButtonEvent;
    private:
        Vector2D mousePosition;
    public:
        MouseButtonInfo() = default;
        /// @brief Creates a MouseInfo with given MouseCode, Action and Vector2D mousePosition
        /// @param code MouseCode, GLFW mousecode storing the mousebutton to which the action is related
        /// @param action Action, stores if the mousebutton was pressed or released, scrolled, moved, dragged
        /// @param mousePosition Vector2D, position of mouse when button action occured
        MouseButtonInfo(MouseCode code, MouseAction action, Vector2D mousePosition);
        ~MouseButtonInfo() = default;
    };

    /// @brief Exception thrown when MouseAction option chosen is invalid for given type of event for mouse
    class InvalidMouseActionException :public std::exception
    {

    };

    /// @brief Base class for all types of mouse events to inherit from
    class MouseEvent : public Event
    {
    protected:
        MouseInfo info;
    public:
        /// @brief Creates a MouseEvent with given info
        /// @param info Mouseinfo, stores information related to the mouse beeing the subject of the event
        MouseEvent(MouseInfo info);
        /// @brief Virtual function that returns name of the even. Will be implemented by derived classes.
        /// @return name of the event, std::string
        virtual std::string ToString() const override = 0;
        /// @brief Gets code of MouseEvent
        /// @return mouse button acted on, MouseCode enum
        MouseCode GetMouseCode() const;
        /// @brief Gets ation of MouseEvent
        /// @return mouse action that occurred, MouseAction enum
        MouseAction GetMouseAction() const;
        virtual ~MouseEvent() = default;
    };

    class MouseButtonEvent : public MouseEvent
    {
    public:
        /// @brief Creates a MouseButtonEvent with given MouseCode, Action and Vector2D mousePosition
        /// @param code  MouseCode, GLFW mousecode storing the mousebutton to which the action is related
        /// @param action Action, stores if the mousebutton was pressed or released, other choices are invalid for MouseButtonEvent
        /// @param mousePosition Vector2D, 2D position of mouse on screen with (0,0) beeing leftmost upper corner
        /// @throws InvalidMouseActionException if wrong type of MouseAction is passed
        MouseButtonEvent(MouseCode code, MouseAction action, Vector2D mousePosition);
        /// @brief Creates a MouseEvent with given info
        /// @param info Mouseinfo, stores information related to the mouse beeing the subject of the event
        MouseButtonEvent(MouseButtonInfo info);
        EVENT_TYPE_TO_STRING(MouseButton);
        /// @brief Creates string information for debug purposes about data related to MouseButtonEvent, showing mouseCode, mouseAction and mousePosition
        /// @return information for logger, std::string
        std::string ToString() const override;
        /// @brief Gets position of MouseButtonEvent
        /// @return mouse position on screen when event occurred, Vector2D object
        Vector2D GetMousePosition() const;
        ~MouseButtonEvent() = default;
    };
}