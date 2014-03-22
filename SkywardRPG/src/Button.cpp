#include "Globals.h"
#include <string>
using namespace Skyward;
using namespace std;
Gui::Button::Button(Gui::GuiElement* c_parent, int c_x, int c_y, string c_label, GenericMemPTR c_on_down, EventCapable* c_instance) : GuiElement(c_parent, c_x, c_y)
{
    if (c_on_down == NULL) c_on_down = &EventCapable::null_function;
    m_color_mod = 0;
    m_mouse_down = new Gui::MouseDownEvent(this);
    m_mouse_over = new Gui::MouseOverEvent(this);
    m_mouse_out = new Gui::MouseOutEvent(this);
    GenericMemPTR c_hover_high = reinterpret_cast<GenericMemPTR>(&Gui::Button::highlight);
    GenericMemPTR c_hover_low = reinterpret_cast<GenericMemPTR>(&Gui::Button::dehighlight);
    m_mouse_over->set_trigger(new Delegate(c_hover_high, this));
    m_mouse_out->set_trigger(new Delegate(c_hover_low, this));
    m_mouse_down->set_trigger(new Delegate(c_on_down, c_instance));
    m_label = c_label;
    m_width = (c_label.size() * 8) + 8;
    m_height = 16;
}

Gui::Button::~Button()
{
    //dtor
}

void Gui::Button::draw_internal()
{
    rectfill(gui_buffer, m_x, m_y, m_x + m_width, m_y + m_height, makecol(70 + m_color_mod, 70 + m_color_mod, 70 + m_color_mod));
    textprintf_ex(gui_buffer, font, m_x + 5, m_y + 5, makecol(0, 100, 243), -1, m_label.c_str());
}
