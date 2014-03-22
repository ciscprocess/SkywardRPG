/*
  Name: MouseDownEvent.cpp
  Copyright: none
  Author: Nathan Korzekwa
  Date: 13/08/10 15:17
  Description: Implementation for MouseDownEvent
*/

#include "Globals.h"

namespace Skyward
{
    namespace Gui
    {
        void MouseDownEvent::check_internal()
        {

            int point_x = parent->get_x();
            int point_y = parent->get_y();
            int width = parent->get_width();
            int height = parent->get_height();
            //point = parent->get_position();
            //size = parent->get_size();
            int _mouse_x = myProg->get_input_manager()->get_mouse_x();
            int _mouse_y = myProg->get_input_manager()->get_mouse_y();
            bool left_button = myProg->get_input_manager()->get_mouse_pressed(1);
            if (_mouse_x > point_x && _mouse_x < point_x + width)
            {
                if (_mouse_y > point_y && _mouse_y < point_y + height && left_button)
                {
                   if (!m_triggered && parent->get_active() && (parent->get_children().size() == 0)) this->on_trigger->execute();
                   m_triggered = true;
                }
                else
                {
                    m_triggered = false;
                }

            }
        }
    }
}
