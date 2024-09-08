/**************************************************************************/
/*  KeyboardEvent.hpp                                                     */
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