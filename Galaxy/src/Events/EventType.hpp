/**************************************************************************/
/*  EventType.hpp                                                             */
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