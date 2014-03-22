#include "MouseOutEvent.h"
#include "Globals.h"
namespace Skyward
{
    void Gui::MouseOutEvent::check_internal()
    {
        int point_x = parent->get_x();
        int point_y = parent->get_y();
        int width = parent->get_width();
        int height = parent->get_height();
        //point = parent->get_position();
        //size = parent->get_size();
        int _mouse_x = myProg->get_input_manager()->get_mouse_x();
        int _mouse_y = myProg->get_input_manager()->get_mouse_y();
        if (_mouse_x > point_x && _mouse_x < point_x + width && _mouse_y > point_y && _mouse_y < point_y + height)
        {
           last_triggered = true;
           m_triggered = false;
        }
        else if (last_triggered)
        {
            if (!m_triggered && parent->get_active()) (this->on_trigger->execute());
            last_triggered = false;
            m_triggered = true;
        }
        else { }
    }
}
