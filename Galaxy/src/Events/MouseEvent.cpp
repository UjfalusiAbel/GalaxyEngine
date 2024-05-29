#include "MouseEvent.h"

namespace Galaxy
{
    MouseEvent::MouseEvent(MouseCode code, MouseAction action, Vector2D mousePosition)
    {
        MouseInfo info;
        info.code = code;
        info.action = action;
        info.mousePosition = mousePosition;
        this->info = info;
    }

    MouseEvent::MouseEvent(MouseInfo info) :info(info)
    {
    }

    std::string MouseEvent::ToString() const
    {
        std::stringstream ss;
        std::string actions[5] = { "button pressed", "button released", "scrolled","moved","dragged" };
        ss << "Mouse event occured with mouse code " << this->info.code;
        ss << " with mouse action " << actions[(int)(this->info.action)];
        ss << " and with mouse position " << this->info.mousePosition.ToString();
        return ss.str();
    }

    MouseCode MouseEvent::GetMouseCode() const
    {
        return this->info.code;
    }

    MouseAction MouseEvent::GetMouseAction() const
    {
        return this->info.action;
    }

    Vector2D MouseEvent::GetMousePosition() const
    {
        return this->info.mousePosition;
    }
}