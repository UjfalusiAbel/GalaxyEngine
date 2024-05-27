#pragma once

#include "EventType.h"

namespace Galaxy
{
    enum Action 
    {
        Pressed = 0,
        Released = 1
    };

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