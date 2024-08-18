#include "../Event.hpp"
#include "../../Core/Utils.hpp"
#include <vector>
#include <functional>

namespace Galaxy
{
    namespace Events
    {
        class IEventListener
        {
        public:
            virtual void UpdateListener() = 0;
        };
    }
}