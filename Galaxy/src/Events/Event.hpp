/**************************************************************************/
/*  Event.hpp                                                             */
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

#include "EventType.hpp"

namespace Galaxy
{
    namespace Events
    {
        /// @brief Event base class where all even types inherit from
        class Event
        {
        private:
            EventType eventType;
            bool wasHandled = false;
        public:
            /// @brief Gets the type of the event that occurred
            /// @return type of the event, EventType : enum
            EventType GetEventType() const;
            /// @brief Virtual function that returns name of the even. Will be implemented by derived classes.
            /// @return name of the event, std::string
            virtual const std::string GetEventName() const = 0;
            /// @brief Virtual function creating string information for logger. Will be implemented by derived classes.
            /// @return information for logger, std::string
            virtual std::string ToString() const = 0;
            virtual ~Event() = default;
        };

        #define EVENT_TYPE_TO_STRING(type) virtual const std::string GetEventName() const override { return #type; }
    }
}