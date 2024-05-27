#pragma once

#include "Event.h"
#include "KeyCodes.h"
#include "sstream"

namespace Galaxy
{
    /// @brief Stores information about code and action related to KeyboardEvent.
    struct KeyInfo
    {
        KeyCode code;
        Action action;
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
        KeyboardEvent(KeyCode code, Action action);
        /// @brief Creates a KeyboardEvent the given KeyInfo
        /// @param info 
        KeyboardEvent(KeyInfo info);
        EVENT_TYPE_TO_STRING(Keyboard)
        /// @brief Creates string information for debug purposes about data related to KeyboardEvent, showing KeyCode and Action 
        /// @return information for logger, std::string
        std::string ToString() const override;
        /// @brief Gets KeyCode of KeyboardEvent
        /// @return keycode of key pressed, KeyCode enum
        KeyCode GetKeyCode() const;
        /// @brief Gets Action of KeyboardEvent
        /// @return action that occurred in event, Action enum
        Action GetKeyAction() const;
    };

}