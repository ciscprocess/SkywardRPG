/*
  Name: GuiManager.h
  Copyright: none
  Author: nkorzekwa
  Date: 09/02/10 23:03
  Description: This is the master class which controls and contains all gui
               objects.
*/
#include <vector>
#include "GuiElement.h"
#include "Event.h"

#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H
namespace Skyward
{
    namespace Gui
    {
        class GuiManager
        {
        public:
               GuiManager();
               void draw_elements();
               void add_element(GuiElement* a_elem);
               void remove_element(int a_id);
               void proctor_events();
               void remove_element(GuiElement* a_elem);
               int get_max_id();
               void add_event(Event2* a_avt);
               //void tie_event();
        private:
               vector<Event2*> event_list;
               vector<GuiElement*> gui_list;
        };
    }
}

#endif
