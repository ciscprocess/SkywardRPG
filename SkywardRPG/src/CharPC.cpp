/*
	CharPC.cpp - this file contains the implementation of CharPC.
*/

#include "Globals.h"
extern BITMAP* buffer;
extern BITMAP* gui_buffer;
namespace Skyward
{
        /* TODO (nkorzekwa#2#): Make constructor overloads use one another */
        
        CharPC::CharPC(BITMAP* c_char_sprite, std::string data_file)
        {
            this->char_sprite = c_char_sprite;
            dx = 0;
            dy = 0;
            s_x = 0;
            s_y = 0;
            cycle_pos = 0;
        } 
        
        CharPC::CharPC(BITMAP* c_char_sprite, BITMAP* c_sheet, int c_x, int c_y)
        {
            this->char_sprite = c_char_sprite;
            this->char_sheet = c_sheet;
            this->x = c_x;
            this->y = c_y;
            dx = 0;
            dy = 0;
            s_x = 0;
            s_y = 0;
            cycle_pos = 0;
        } 
        
        CharPC::~CharPC()
        {
            delete this->char_sprite;
        } 
        
        void CharPC::inc_coordinates(int a_x, int a_y)
        {
             this->dx = a_x; 
             this->dy = a_y; 
             int trav = 0;
             int x_mod = 0;
             int y_mod = 0;
             
             int y_ext = 0;
             int x_ext = 0;
             
             if (a_x != 0) y_ext = 18;
             if (a_y != 0) x_ext = 18;
             
             if (a_x > 0) x_mod = 18;
             if (a_y > 0) y_mod = 18;
             ScreenPanel* _panel = myProg->get_world()->get_screen();
             trav = _panel->get_traversable(this->x + dx, this->y + dy); 
                  
             
             if (trav != -1)
             {
                trav = _panel->get_traversable(this->x + dx + x_mod, this->y + dy + y_mod)
                & _panel->get_traversable(this->x + dx + x_mod + x_ext, this->y + dy + y_mod + y_ext);
             }
             
             if (trav == 1)
             {
                 this->x += a_x; 
                 this->y += a_y; 
             }
             else if (trav == 0)
             {
                  
             }
             else if (trav < 0)
             {
                  myProg->get_world()->pan_screen(this->x + dx + x_mod, this->y + dy + y_mod, true); //Pan Screen
             }
             
             if (dx < 0) s_y = 96;
             else if (dx > 0) s_y = 32;
             if (dy < 0) s_y = 0;
             else if (dy > 0) s_y = 64;
             updated = true;
        }
        
        void CharPC::draw()
        {
              ScreenPanel* _panel = myProg->get_world()->get_screen();
              //clear_to_color(buffer, makecol(255,255,255));
              _panel->draw_to_screen(this->x - dx, this->y - dy, 
             (this->x) + 20, (this->y) + 20);
             //myProg->get_world()->get_screen()->draw_to_screen();
             
             if (key[KEY_SPACE]) //draw_sprite(buffer, this->char_sheet, this->x, this->y);
             {
                 BITMAP* eatmyshorts = create_bitmap(20, 25);
                 clear_to_color(eatmyshorts, makecol(255, 0, 255));
                 masked_stretch_blit(this->char_sheet, eatmyshorts, 0, 96, 20, 24, 0, 0,  20, 25);
                 
             }
             masked_stretch_blit(this->char_sheet, buffer, s_x, s_y, 20, 25, this->x, this->y,  20, 25);
             
             updated = false;
        }
        
        void CharPC::iterate_animation(int speed)
        {
             if (cycle_pos >= 60 / speed) cycle_pos = 0;
             
             if (cycle_pos >= 40 / speed)
             {
                 s_x = 24;
             }
             
             else if (cycle_pos >= 20 / speed)
             {
                 s_x = 48;
             }
             
             else if (cycle_pos >= 0)
             {
                  s_x = 0;
             }
             
             cycle_pos++;
        }
}
