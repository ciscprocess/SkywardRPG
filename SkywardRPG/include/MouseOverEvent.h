/*
  Name: MouseOverEvent.h
  Copyright: none
  Author: Nathan Korzekwa
  Date: 25/03/10 10:24
  Description: Event that triggers when mouse is over a GuiElement derived element.
*/
#include "Event.h"
#ifndef MOUSE_OVER_EVENT_H
#define MOUSE_OVER_EVENT_H
namespace Skyward
{
    namespace Gui
    {
        class MouseOverEvent : public Skyward::Gui::Event2, public EventCapable
        {

            public:
            MouseOverEvent(GuiElement *c_parent) : Event2(c_parent) { };
            private:
              virtual void check_internal();
              int mouse_x;
              int mouse_y;
        };
    }
}
#endif
