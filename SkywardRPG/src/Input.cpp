/*
	Program.cpp - this file contains the implementations of the functions in the namespace Input.
*/
#include "Globals.h"

namespace Skyward
{

    InputManager::InputManager()
    {
        mickey_x = 0;
        mickey_y = 0;
        this->m_mouse_x = 0;
        this->m_mouse_y = 0;
    }

    void InputManager::poll_game_keys()
    {
        const int modulusVal = 1;
        if (key[KEY_UP])
        {
           myProg->get_world()->shift_char_coordinates(0,-modulusVal);
        }

        if (key[KEY_DOWN])
        {
           myProg->get_world()->shift_char_coordinates(0,modulusVal);
        }

        if (key[KEY_LEFT])
        {
           myProg->get_world()->shift_char_coordinates(-modulusVal,0);
        }

        if (key[KEY_RIGHT])
        {
           myProg->get_world()->shift_char_coordinates(modulusVal,0);
        }

        if (key[KEY_R])
        {
            myProg->get_world()->shift_char_coordinates(-1 * myProg->get_world()->get_character(0)->get_x(), myProg->get_world()->get_character(0)->get_y());
        }
    }

    void InputManager::poll_mouse()
    {
       get_mouse_mickeys(&mickey_x, &mickey_y);
       this->m_mouse_x = mouse_x;
       this->m_mouse_y = mouse_y;
       if (mickey_x != 0 || mickey_y != 0)
       {

       }
       if (mouse_b & 1)
       {
           //myProg->s_log->info("poll_mouse works.....");
           this->left_m = true;
       }
       else
       {
           //myProg->s_log->info("poll_mouse works a little too well...");
          this->left_m = false;
       }

       if (mouse_b & 2)
       {
           this->right_m = true;
       }
       else
       {
           this->right_m = false;
       }
   }

   void InputManager::draw_cursor()
   {
        fastline(gui_buffer, mouse_x, mouse_y, mouse_x + 10, mouse_y + 10, makecol(255,255,255));
        fastline(gui_buffer, mouse_x, mouse_y, mouse_x + 5, mouse_y, makecol(255,255,255));
        fastline(gui_buffer, mouse_x, mouse_y, mouse_x, mouse_y + 5, makecol(255,255,255));
   }
}
