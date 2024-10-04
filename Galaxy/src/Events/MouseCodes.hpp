/**************************************************************************/
/*  KeyCodes.hpp                                                          */
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

#include <cstdint>

namespace Galaxy
{
    namespace Events
    {
        ///@brief GLFW button codes for mouse
        enum MouseCode
        {
            //From glfw3.h
            GLFW_MOUSE_BUTTON_1 = 0,
            GLFW_MOUSE_BUTTON_2 = 1,
            GLFW_MOUSE_BUTTON_3 = 2,
            GLFW_MOUSE_BUTTON_4 = 3,
            GLFW_MOUSE_BUTTON_5 = 4,
            GLFW_MOUSE_BUTTON_6 = 5,
            GLFW_MOUSE_BUTTON_7 = 6,
            GLFW_MOUSE_BUTTON_8 = 7,

            GLFW_MOUSE_BUTTON_LAST = GLFW_MOUSE_BUTTON_8,
            GLFW_MOUSE_BUTTON_LEFT = GLFW_MOUSE_BUTTON_1,
            GLFW_MOUSE_BUTTON_RIGHT = GLFW_MOUSE_BUTTON_2,
            GLFW_MOUSE_BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_3,
        };
    }
}