/*
  Name: GuiElement.h
  Copyright: none
  Author: nkorzekwa
  Date: 09/02/10 23:18
  Description: This is the generic base class from which all Gui Elements will
               derive from.
*/
#include <vector>
#include "EventCapable.h"
#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H
using namespace std;
namespace Skyward
{
    namespace Gui
    {
        class MouseOverEvent ;
        class MouseDownEvent ;
        class MouseOutEvent ;

        class GuiElement : public EventCapable
        {
        public:
            GuiElement(Skyward::Gui::GuiElement* c_parent, int c_x, int c_y);
            virtual void resize(int a_width, int a_height);
            virtual void hide();
            virtual void show();
            virtual void destroy();
            virtual void move(int a_x, int a_y);
            virtual void mouse_move();
            virtual void move_window();
            virtual void add_element(GuiElement *a_elem);
            virtual void set_parent(GuiElement *a_parent);
            virtual int get_x() { return m_x; }
            virtual int get_y() { return m_y; }
            virtual int get_width() { return m_width; }
            virtual int get_height() { return m_height; }
            virtual bool get_active();
            vector<GuiElement*> get_children() { return m_children; }
            void draw();
            void add_child(GuiElement *a_child);
            bool get_visible() { return m_visible; }
            int get_id() { return m_id; }
        protected:
            GuiElement *parent;
            int m_id;
            int m_x;
            int m_y;
            int m_relative_x;
            int m_relative_y;
            int m_width;
            int m_height;
            int m_z_index;
            vector<GuiElement*> m_children;
            bool m_visible;
            bool m_clicked;
            MouseOverEvent* m_mouse_over;
            MouseDownEvent* m_mouse_down;
            MouseOutEvent* m_mouse_out;
            virtual void draw_internal();
            virtual void draw_children();

        private:
            //virtual void abstract_class() = 0; //This class is now abstract. :-(

        };
    }
}
#define END_GUIELEMENT
#endif
