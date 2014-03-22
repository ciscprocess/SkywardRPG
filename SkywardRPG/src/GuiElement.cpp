/*
  Name: GuiElement.cpp
  Copyright: none
  Author: Nathan Korzekwa
  Date: 12/08/10 20:50
  Description: Implementation
*/

#include "Globals.h"
#ifndef GUIMANAGER_H
#define GUIMANAGER_H
using namespace Gui;
namespace Skyward
{
    Gui::GuiElement::GuiElement(Skyward::Gui::GuiElement* c_parent, int c_x, int c_y)
    {
        if (c_parent)
        {
            this->m_x = c_x + c_parent->get_x();
            this->m_y = c_y + c_parent->get_y();
        }
        this->m_x = c_x;
        this->m_y = c_y;
        this->m_relative_x = c_x;
        this->m_relative_y = c_y;
        parent = c_parent;
        this->m_id = myProg->get_gui_manager()->get_max_id() + 1;
        this->m_visible = true;
        this->m_clicked = false;
        //myProg->s_log->info("IN GuiElem constr");
        //myProg->m_gui->remove_element(0);
    }

    void Gui::GuiElement::resize(int a_width, int a_height)
    {
        this->m_width = a_width;
        this->m_height = a_height;
    }

    void Gui::GuiElement::hide()
    {
        m_visible = false;
        for (unsigned int for_index = 0; for_index < m_children.size(); for_index++)
        {
            m_children[for_index]->hide();
        }
    }

    void Gui::GuiElement::add_element(GuiElement *a_elem)
    {
        a_elem->set_parent(this);
        m_children.push_back(a_elem);
    }

    bool Gui::GuiElement::get_active()
    {
        bool ret_val = (m_width > 0) && (m_height > 0) && m_visible;
        return ret_val;
    }

    void Gui::GuiElement::show()
    {
        m_visible = true;
        for (unsigned int for_index = 0; for_index < m_children.size(); for_index++)
        {
            m_children[for_index]->show();
        }
    }

    void Gui::GuiElement::set_parent(GuiElement *a_parent)
    {
        this->parent = a_parent;
        this->m_x += this->parent->get_x();
        this->m_y += this->parent->get_y();
    }

    void Gui::GuiElement::move(int a_x, int a_y)
    {
        if (this->parent)
        {
            this->m_x = a_x + parent->get_x();
            this->m_y = a_y + parent->get_x();
        }

        this->m_relative_x = a_x;
        this->m_relative_x = a_y;
    }

    void Gui::GuiElement::destroy()
    {
        GuiManager* t_gui = myProg->get_gui_manager();

        t_gui->remove_element(this);
    }

    void Gui::GuiElement::mouse_move()
    {
        this->m_mouse_over = new Gui::MouseOverEvent(this);
        //void (GuiElement::*_temp)() = (&GuiElement::move_window);
        //GenericMemPTR _temp2 = reinterpret_cast<GenericMemPTR>(_temp);
        //m_mouse_over->set_trigger(_temp2);
    }

    void Gui::GuiElement::move_window()
    {
        myProg->s_log->warning("Base GuiElement.move_window() called. This handler is left empty by default -- you may have some bad code.");
    }

    void Gui::GuiElement::draw()
    {
        this->draw_internal();
        this->draw_children();
    }

    void Gui::GuiElement::draw_internal()
    {
        myProg->s_log->warning("Base GuiElement.draw_internal() called. Nothing to draw.");
    }

    void Gui::GuiElement::add_child(GuiElement *a_child)
    {
        this->m_children.push_back(a_child);
        a_child->set_parent(this);
    }

    void Gui::GuiElement::draw_children()
    {
        for (unsigned int for_index = 0; for_index < m_children.size(); for_index++)
        {
            m_children[for_index]->draw();
        }
    }
}
#endif
