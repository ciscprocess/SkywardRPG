/*
    CharPC.h - this file contains all of the headers for the namespace Input,
    where Input is a collection of functions that recognize and handle user input.
*/
#ifndef INPUT_H
        #define INPUT_H
namespace Skyward
{
    class InputManager
    {
       private: 
       
       int mickey_x;
       int mickey_y;
       int m_mouse_x;
       int m_mouse_y;
       bool right_m;
       bool left_m;
       public: 
       
       int get_mouse_x() { return m_mouse_x;}
       int get_mouse_y() { return m_mouse_y; }
       bool get_mouse_pressed(int a_loc) { if (a_loc > 0) return left_m; else return right_m; }
       
       InputManager();
       
       void poll_game_keys();
       
       void poll_mouse();

       
       void draw_cursor();

        
    };
}
#endif
