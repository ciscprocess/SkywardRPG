/*
  Name: Event.cpp
  Copyright: none
  Author: nkorzekwa
  Date: 09/08/10 16:22
  Description: Event Implementation
*/
#include "Globals.h"
#include "Delegate.h"
namespace Skyward
{
    Gui::Event2::Event2(GuiElement *c_parent)
    {
        //myProg->s_log->warning("Base Event type has been created. Normally, this should not happen; check your code.");
        this->parent = c_parent;
        myProg->get_gui_manager()->add_event(this);
        m_triggered = false;
    }

    void Gui::Event2::set_trigger(Delegate *c_on_trigger)
    {
         on_trigger = c_on_trigger;
    }

    void Gui::Event2::check()
    {
         if (parent->get_visible())
            check_internal();
    }

    void Gui::Event2::check_internal()
    {
         myProg->s_log->warning("No stars shine upon the Doomstone.");
    }
}
