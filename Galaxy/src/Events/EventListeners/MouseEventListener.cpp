#include "MouseEventListener.hpp"

namespace Galaxy
{
    namespace Events
    {
        bool MouseEventListener::CheckIfOnTopLayer() const
        {
            return this->currentlyOnTopLayer;
        }

        bool MouseEventListener::BringToTopLayer()
        {
            this->currentlyOnTopLayer = true;
        }

        bool MouseEventListener::PutIntoBackground()
        {
            this->currentlyOnTopLayer = false;
        }

        void MouseEventListener::UpdateListener()
        {
            //TODO implement
        }
    }
}