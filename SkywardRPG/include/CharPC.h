/*
    CharPC.h - this file contains all of the headers for the class CharPC,
    where CharPC represents any playable character.
*/
#include <allegro.h>
#include <string>
#ifndef CHARPC_H
        #define CHARPC_H

namespace Skyward
{
    class CharPC
    {
    public:
           CharPC(BITMAP* c_char_sprite, std::string data_file);
           CharPC(BITMAP* c_char_sprite, BITMAP* c_sheet, int c_x, int c_y);
           ~CharPC();
           void draw();
           void inc_coordinates(int a_x, int a_y);
           void iterate_animation(int speed);
           void set_animation(int position);
           int get_status(int type) { throw "Not yet implemented"; }; //Wtf?
           int get_x() { return this->x; }
           int get_y() { return this->y; }



    private:
            BITMAP* char_sprite;
            BITMAP* char_sheet;
            int x;
            int y;
            int s_x;
            int s_y;
            int dx;
            int dy;
            int cycle_pos;
            bool updated;
            bool dynamic;
            bool asyncronous;
    };
}
#endif
