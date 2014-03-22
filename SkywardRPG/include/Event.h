/*
  Name: Event.h
  Copyright: none
  Author: Nathan Korzekwa
  Date: 24/03/10 21:20
  Description: This file contains a generic event class. It allows you to program
  custom behavior based on fickle input, such as one by your typical user.
  Unfortunately, Events can only be used for objects Derived from GuiElement
  thanks to the so-called geniuses at the ISO C++ committee. For whatever reason,
  these old men decided that having a greek-derived syntax for  pointers to member
  functions wasn't enough, and they disallowed any kind of universal pointer
  member function declaration and restricted it to one class. Even better, the
  lovely folks who crafted the MinGW compiler that this source is made for
  decided to disallow casts between functions of different classes.(Although, grudgingly, for a good reason).
  So, don't blame me for this unfortunate restriction, rather, blame the damn ISO committee.
  Feel free to drop them a line at: webmaster@open-std.org, just don't get too close;
  you might get herpes.

  NOTE: The above text is outdated. I've circumvented the restriction.
*/

#ifndef EVENT_H
#define EVENT_H

#include "GuiElement.h"
#include "EventCapable.h"
#include "Delegate.h"

namespace Skyward
{
    namespace Gui
    {
        class Event2
        {

        public:
               Event2(GuiElement *c_parent);
               Delegate *on_trigger;
               void check();
               virtual void set_trigger(Delegate *c_on_trigger);
               GuiElement* get_parent() { return this->parent; }
        protected:
              GuiElement *parent;
              bool m_triggered;
              virtual void check_internal();
        };
    }
}
#endif
