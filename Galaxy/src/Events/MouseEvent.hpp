/**************************************************************************/
/*  MouseEvent.hpp                                                        */
/**************************************************************************/
/* This file is part of Galaxy Engine https://github.com/UjfalusiAbel/GalaxyEngine */
/*
 * Galaxy Engine
 * Copyright © 2024 - present Ujfalusi Ábel
 *
 * Permission is hereby denied to commercially use, distribute, or replicate this software, including any modified versions, in any form or by any means, electronic or mechanical, without the express written permission of the software owner (Ujfalusi Ábel).
 *
 * Products (games or software) created using this software cannot be commercially used, distributed, or replicated without express written permission from the software owner (Ujfalusi Ábel).
 *
 * This software is provided "as is", without any warranty of any kind, express or implied, including but not limited to warranties of merchantability, fitness for a particular purpose, or non-infringement. The software owner shall not be held liable for any claim, damages, or other liabilities arising from its use or distribution.
 *
 * This license is governed by the laws of Romania, and any legal action must be brought in the courts of Romania.
 *
 * For commercial inquiries, please contact: abelujfalusi4@gmail.com or visit ujfalusiabel.fly.dev
 */

#pragma once

#include "Event.hpp"
#include "MouseCodes.hpp"
#include <string>
#include <sstream>
#include <exception>
#include <Core/Utils.hpp>
#include <Math/Vector2D.hpp>

namespace Galaxy
{
    namespace Events
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
            friend MouseButtonEvent;
        protected:
            MouseCode code;
            MouseAction action;
            Math::Vector2D mousePosition;
        public:
            MouseInfo() = default;
            /// @brief Creates a MouseInfo with given MouseCode, Action and Vector2D mousePosition
            /// @param code MouseCode, GLFW mousecode storing the mousebutton to which the action is related
            /// @param action Action, stores if the mousebutton was pressed or released, scrolled, moved, dragged
            /// @param mousePosition Vector2D, position of mouse when button action occured
            MouseInfo(MouseCode code, MouseAction action, Math::Vector2D mousePosition);
            virtual ~MouseInfo() = default;
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
            MouseButtonEvent(MouseCode code, MouseAction action, Math::Vector2D mousePosition);
            /// @brief Creates a MouseEvent with given info
            /// @param info Mouseinfo, stores information related to the mouse beeing the subject of the event
            MouseButtonEvent(MouseInfo info);
            EVENT_TYPE_TO_STRING(MouseButton);
            /// @brief Creates string information for debug purposes about data related to MouseButtonEvent, showing mouseCode, mouseAction and mousePosition
            /// @return information for logger, std::string
            std::string ToString() const override;
            /// @brief Gets position of MouseButtonEvent
            /// @return mouse position on screen when event occurred, Vector2D object
            Math::Vector2D GetMousePosition() const;
            ~MouseButtonEvent() = default;
        };
    }
}