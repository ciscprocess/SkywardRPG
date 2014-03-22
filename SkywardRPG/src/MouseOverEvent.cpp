/*
  Name: MouseOverEvent.cpp
  Copyright: none
  Author: Nathan Korzekwa
  Date: 12/08/10 15:38
  Description: Implementation
*/
#include "Globals.h"
#include <sstream>
using namespace std;
namespace Skyward
{
    //Gui::MouseOverEvent::MouseOverEvent(GuiElement *c_parent)
    //{
        //Event2(c_parent);
      //  this->parent = c_parent;
    //}

    void Gui::MouseOverEvent::check_internal()
    {
        //myProg->s_log->info("Well, it hit check....");
        int point_x = parent->get_x();
        int point_y = parent->get_y();
        int width = parent->get_width();
        int height = parent->get_height();
        //point = parent->get_position();
        //size = parent->get_size();
        int _mouse_x = myProg->get_input_manager()->get_mouse_x();
        int _mouse_y = myProg->get_input_manager()->get_mouse_y();

        //myProg->s_log->info(_msg);

        if (_mouse_x > point_x && _mouse_x < point_x + width)
        {
            if (_mouse_y > point_y && _mouse_y < point_y + height)
            {
               if (!m_triggered && parent->get_active()) (this->on_trigger->execute());
               m_triggered = true;
            }
            else
            {
                m_triggered = false;
            }

        }
    }
}
