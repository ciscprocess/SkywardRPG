#ifndef MOUSEOUTEVENT_H
#define MOUSEOUTEVENT_H

#include "Event.h"

namespace Skyward
{
    namespace Gui
    {
        class MouseOutEvent : public Skyward::Gui::Event2, public EventCapable
        {
            public:
                MouseOutEvent(GuiElement *c_parent) : Event2(c_parent) { };
            private:
                virtual void check_internal();
                int mouse_x;
                int mouse_y;
                bool last_triggered;

        };
    }
}

#endif // MOUSEOUTEVENT_H
