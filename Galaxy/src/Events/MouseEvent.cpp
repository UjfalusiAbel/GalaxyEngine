#include "MouseEvent.h"

namespace Galaxy
{
    MouseInfo::MouseInfo(MouseCode code, MouseAction action):code(code),action(action)
    {
    }

    MouseButtonInfo::MouseButtonInfo(MouseCode code, MouseAction action, Vector2D mousePosition) :MouseInfo(code, action), mousePosition(mousePosition)
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

    MouseButtonEvent::MouseButtonEvent(MouseCode code, MouseAction action, Vector2D mousePosition) :MouseEvent(MouseButtonInfo(code, action, mousePosition))
    {
    }

    MouseButtonEvent::MouseButtonEvent(MouseButtonInfo info) :MouseEvent(info)
    {
    }

    Vector2D MouseButtonEvent::GetMousePosition() const
    {
        const MouseButtonInfo* bInfo = dynamic_cast<const MouseButtonInfo*>(&info);
        return bInfo->mousePosition;
    }

    std::string MouseButtonEvent::ToString() const
    {
        const MouseButtonInfo* bInfo = dynamic_cast<const MouseButtonInfo*>(&info);
        std::stringstream ss;
        std::string actions[5] = { "button pressed", "button released", "scrolled","moved","dragged" };
        ss << "Mouse event occured with mouse code " << bInfo->code;
        ss << " with mouse action " << actions[(int)(bInfo->action)];
        ss << " and with mouse position " << bInfo->mousePosition.ToString();
        return ss.str();
    }
}