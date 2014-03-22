/*
  Name: MouseDownEvent.h
  Copyright: none
  Author: Nathan Korzekwa
  Date: 13/08/10 13:33
  Description: MouseDownEvent catches a mouse click on its parent GuiElement.
*/
#include "GuiElement.h"
#include "Event.h"

#ifndef MOUSEDOWNEVENT_H
#define MOUSEDOWNEVENT_H
namespace Skyward
{
    namespace Gui
    {
        class MouseDownEvent : public Event2, public EventCapable
        {

              public:
                  MouseDownEvent(GuiElement *c_parent) : Event2(c_parent) { };
              private:
                  virtual void check_internal();
                  int mouse_x;
                  int mouse_y;
                  int mouse_b;
        };
    }
}
#endif

