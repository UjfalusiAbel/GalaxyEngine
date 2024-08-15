#include "Event.hpp"

namespace Galaxy
{
    namespace Events
    {
        EventType Event::GetEventType() const
        {
            return this->eventType;
        }
    }
}