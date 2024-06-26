#include "KeyboardEvent.h"

namespace Galaxy 
{
    KeyboardEvent::KeyboardEvent(KeyCode code, KeyAction action)
    {
        KeyInfo info;
        info.code = code;
        info.action = action;
        this->info = info;
    }

    KeyboardEvent::KeyboardEvent(KeyInfo info):info(info)
    {
    }

    std::string KeyboardEvent::ToString() const
    {
        std::stringstream ss;
        std::string actions[2] = {"pressed", "released"};
        ss<<"Keyboard event occured with keycode " <<this->info.code;
        ss<<" and with key action "<< actions[(int)(this->info.action)];
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

};