/*
  Name: GuiManager.cpp
  Copyright: none
  Author: Nathan Korzekwa
  Date: 12/08/10 21:53
  Description: Impl
*/
#include "Globals.h"
#include <vector>
using namespace std;
namespace Skyward
{
    Gui::GuiManager::GuiManager()
    {

    }

    void Gui::GuiManager::draw_elements()
    {
        for (unsigned int for_index = 0; for_index < this->gui_list.size(); for_index++)
        {
         if (gui_list[for_index]->get_visible()) gui_list[for_index]->draw();
        }
    }

    void Gui::GuiManager::add_element(GuiElement* a_elem)
    {
        this->gui_list.push_back(a_elem);
    }

    void Gui::GuiManager::remove_element(GuiElement* a_elem)
    {
        for (unsigned int for_index = 0; for_index < this->gui_list.size(); for_index++)
        {
            if (gui_list[for_index] == a_elem)
            {
                gui_list.erase(gui_list.begin() + for_index);
            }
        }
        int iter1 = 0;
        int iter2 = 0;
        int iter3 = 0;
        int t_deleted = 0;
        //allegro_message("Event Size: %d, Chillin' size: %d", event_list.size(), a_elem->get_children().size());
        vector<GuiElement*> tamp = a_elem->get_children();
        //int t_limit = this->event_list.size();
        for (unsigned int for_index = 0; for_index < this->event_list.size(); for_index++)
        {
            if (t_deleted > 0) for_index -= 1;
            t_deleted = 0;
            if (this->event_list.size() == 0) break;
            if (event_list[for_index] == NULL) break;
            iter3++;
            //allegro_message("for_index: %d", for_index);
            if (event_list[for_index]->get_parent() == a_elem)
            {
                delete event_list[for_index];
                //myProg->s_log->info("Got into delete.");
                event_list.erase(event_list.begin() + for_index);
                for_index = -1;
            }
            //allegro_message("for_index time 2: %d", for_index);
            for (unsigned int for_index2 = 0; for_index2 < a_elem->get_children().size(); for_index2++)
            {
                //allegro_message("for_index time 3: %d", for_index);
                iter1++;
                GuiElement* t_g_elem = a_elem->get_children()[for_index2];
                if (event_list[for_index]->get_parent() == t_g_elem)
                {
                    //allegro_message("for_index time 4: %d", for_index);
                    Event2* temprevent = event_list[for_index];
                    iter2++;
                    event_list.erase(event_list.begin() + for_index);
                    delete temprevent;
                    //myProg->s_log->info("Got into delete2.");
                    t_deleted++;
                }
                else
                {
                    //myProg->s_log->info("Not into delete2.");
                }
            }
        }

        for (unsigned int for_index2 = 0; for_index2 < a_elem->get_children().size(); for_index2++)
        {
            GuiElement* t_g_elem = a_elem->get_children()[for_index2];
            if (event_list[0]->get_parent() == t_g_elem)
            {
                //allegro_message("for_index time 4: %d", for_index);
                Event2* temprevent = event_list[0];
                event_list.erase(event_list.begin() + 0);
                delete temprevent;
                //myProg->s_log->info("Got into delete2-1.");
            }
        }

        for (unsigned int for_index = 0; for_index < a_elem->get_children().size(); for_index++)
        {
            delete a_elem->get_children()[for_index];
        }
        //allegro_message("Iter1: %d, Iter2: %d, Iter3: %d", iter1, iter2, iter3);
        delete a_elem;
    }

    void Gui::GuiManager::remove_element(int a_id)
    {

    }

    int Gui::GuiManager::get_max_id()
    {
        int max_id = 0;
        for (unsigned int for_index = 0; for_index < this->gui_list.size(); for_index++)
        {
            if (gui_list[for_index]->get_id() > max_id) max_id = gui_list[for_index]->get_id();
        }
        return max_id;
    }

    void Gui::GuiManager::proctor_events()
    {
        for (unsigned int for_index = 0; for_index < this->event_list.size(); for_index++)
        {
            event_list[for_index]->check();
        }
    }

    void Gui::GuiManager::add_event(Event2* a_avt)
    {
        event_list.push_back(a_avt);
    }
}
