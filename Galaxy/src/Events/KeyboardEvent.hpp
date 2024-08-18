#pragma once

#include "Event.hpp"
#include "KeyCodes.hpp"
#include "sstream"

namespace Galaxy
{
    namespace Events
    {
        /// @brief Action type related to keyboard keys
        enum KeyAction
        {
            KeyPressed = 0,
            KeyReleased = 1
        };

        /// @brief Stores information about code and action related to KeyboardEvent.
        struct KeyInfo
        {
            KeyCode code;
            KeyAction action;
        };

        /// @brief Event that occurs when a key is pressed or released on the keyboard
        class KeyboardEvent : public Event
        {
        private:
            KeyInfo info;
        public:
            /// @brief Creates a KeyboardEvent with given KeyCode and Action
            /// @param code  KeyCode, GLFW keycode storing the key to which the action is related
            /// @param action Action, stores if the key was pressed or released
            KeyboardEvent(KeyCode code, KeyAction action);
            /// @brief Creates a KeyboardEvent the given KeyInfo
            /// @param info KeyInfo, stores information related to the key being subjected to the event
            KeyboardEvent(KeyInfo info);
            EVENT_TYPE_TO_STRING(Keyboard)
            /// @brief Creates string information for debug purposes about data related to KeyboardEvent, showing KeyCode and Action 
            /// @return information for logger, std::string
            std::string ToString() const override;
            /// @brief Gets code of KeyboardEvent
            /// @return keycode of key activated on, KeyCode enum
            KeyCode GetKeyCode() const;
            /// @brief Gets action of KeyboardEvent
            /// @return action that occurred in event, Action enum
            KeyAction GetKeyAction() const;
            ~KeyboardEvent() = default;
        };
    }

}