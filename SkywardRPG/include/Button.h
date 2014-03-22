#ifndef BUTTON_H
#define BUTTON_H

#include "GuiElement.h"
#include <string>
using namespace std;

namespace Skyward
{
    namespace Gui
    {
        class Button : public GuiElement
        {
            public:
                Button(GuiElement* c_parent, int c_x, int c_y, string c_label,GenericMemPTR c_on_down, EventCapable* c_instance);
                virtual ~Button();
                void highlight() { m_color_mod = 10;}
                void dehighlight() { m_color_mod = 0;}
            protected:
                string m_label;
                virtual void draw_internal();
                int m_color_mod;
            private:
        };
    }
}

#endif // BUTTON_H
