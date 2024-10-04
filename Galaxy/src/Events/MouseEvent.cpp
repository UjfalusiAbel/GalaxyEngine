/**************************************************************************/
/*  MouseEvent.cpp                                                        */
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

#include "MouseEvent.hpp"

namespace Galaxy
{
    namespace Events
    {
        MouseInfo::MouseInfo(MouseCode code, MouseAction action, Math::Vector2D mousePosition) :code(code), action(action), mousePosition(mousePosition)
        {
        }

        MouseEvent::MouseEvent(MouseInfo info) :info(info)
        {
        }

        MouseCode MouseEvent::GetMouseCode() const
        {
            return this->info.code;
        }

        MouseAction MouseEvent::GetMouseAction() const
        {
            return this->info.action;
        }

        MouseButtonEvent::MouseButtonEvent(MouseCode code, MouseAction action, Math::Vector2D mousePosition) :MouseEvent(MouseInfo(code, action, mousePosition))
        {
        }

        MouseButtonEvent::MouseButtonEvent(MouseInfo info) :MouseEvent(info)
        {
        }

        Math::Vector2D MouseButtonEvent::GetMousePosition() const
        {
            return this->info.mousePosition;
        }

        std::string MouseButtonEvent::ToString() const
        {
            std::stringstream ss;
            std::string actions[5] = { "button pressed", "button released", "scrolled","moved","dragged" };
            ss << "Mouse event occured with mouse code " << this->info.code;
            ss << " with mouse action " << actions[(int)(this->info.action)];
            ss << " and with mouse position " << this->info.mousePosition.ToString();
            return ss.str();
        }
    }
}