/*
  Name: MessageBox.cpp
  Copyright: none
  Author: Nathan Korzekwa
  Date: 12/08/10 23:20
  Description: Implementation of MessageBox
*/
#include "Globals.h"
#include "LogEventWriter.h"
#include "Delegate.h"
#include <math.h>
namespace Skyward
{
    namespace Gui
    {
        MessageBox::MessageBox(Skyward::Gui::GuiElement* c_parent, int c_x, int c_y, int c_width, int c_height, string c_message) : GuiElement(c_parent, c_x, c_y)
        {
            //GuiElement(c_parent, c_x, c_y);
            m_message = c_message;
            this->m_width = c_width;
            this->m_height = c_height;
            float gorg1 = (float)(m_width - 32);
            float tt_letts = gorg1 / 8.0;
            this->m_letts = (int)floor(tt_letts);
            float t_lines = (float)c_message.size() / (float)m_letts;
            //allegro_message("Letts: %f", t_lines);
            this->m_lines = ceil(t_lines);
            GenericMemPTR _temp3 = reinterpret_cast<GenericMemPTR>(&GuiElement::hide);
            this->add_child(new Button(NULL,m_width - 16, 0, "x", _temp3, this));
        }

        void MessageBox::deutsche()
        {
            allegro_message("Hai");
            m_visible = false;
        }

        void MessageBox::Llog()
        {
            textprintf_ex(gui_buffer, font, 400, 400, makecol(0, 100, 243), makecol(0, 0, 0), "Addition.");
        }

        void MessageBox::Llog2()
        {

        }

        void MessageBox::draw_internal()
        {
            rectfill(gui_buffer, m_x, m_y, m_x + m_width, m_y + m_height, makecol(40, 40, 40));
            for (unsigned int for_index = 0; for_index < m_lines; for_index++)
            {
                int t_pos = ((for_index +1) * m_letts);
                if ((for_index +1) * m_letts >= m_message.size())
                    t_pos = m_message.size() - 1;
                int t_pos0 = for_index * m_letts;
                //allegro_message("Letts: %d, Diff: %d", m_letts, t_pos - t_pos0);
                if (t_pos - t_pos0 > m_letts) allegro_message("Anyone wanna pound my ?");
                string t_message = m_message.substr(t_pos0, m_letts);
                textprintf_ex(gui_buffer, font, m_x + 5, m_y + 5 + (9 * for_index), makecol(0, 100, 243), -1, t_message.c_str());
            }

        }
    }
}
