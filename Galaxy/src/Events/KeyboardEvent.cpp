/**************************************************************************/
/*  KeyboardEvent.cpp                                                     */
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

#include "KeyboardEvent.hpp"

namespace Galaxy
{
    namespace Events
    {
        KeyboardEvent::KeyboardEvent(KeyCode code, KeyAction action)
        {
            KeyInfo info;
            info.code = code;
            info.action = action;
            this->info = info;
        }

        KeyboardEvent::KeyboardEvent(KeyInfo info) :info(info)
        {
        }

        std::string KeyboardEvent::ToString() const
        {
            std::stringstream ss;
            std::string actions[2] = { "pressed", "released" };
            ss << "Keyboard event occured with keycode " << this->info.code;
            ss << " and with key action " << actions[(int)(this->info.action)];
            return ss.str();
        }

        KeyCode KeyboardEvent::GetKeyCode() const
        {
            return this->info.code;
        }

        KeyAction KeyboardEvent::GetKeyAction() const
        {
            return this->info.action;
        }
    }

};