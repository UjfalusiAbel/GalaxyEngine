#include "IEventListener.hpp"

namespace Galaxy
{
    namespace Events
    {
        class MouseEventListener :IEventListener
        {
        private:
            bool currentlyOnTopLayer;
        public:
            bool CheckIfOnTopLayer() const;
            bool BringToTopLayer();
            bool PutIntoBackground();
            void UpdateListener() override;
        };
    }
}