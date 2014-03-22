/*
    World.h - this file contains all of the headers for the class World,
    where World represents a collection of Screen objects, as well as all
    parenting methods involved
*/

#include "ScreenPanel.h"

#include "CharPC.h"
#include "Tile.h"
#include "ObjectManager.h"
#include <vector>
#ifndef WORLD_H
        #define WORLD_H
namespace Skyward
{
    class ObjectManager ;
    enum ControlKeys {CHAR_STATIC = 0, CHAR_UP = 110, CHAR_DOWN = 111, CHAR_RIGHT = 112, CHAR_LEFT = 113};
          class World
          {
          public:
                World(int x, int y);
                ~World();
                static const int MAX_CHARS = 4;
                ScreenPanel* get_screen(int screen_x, int screen_y) { return map[screen_x][screen_y]; }
                ScreenPanel* get_screen() { return map[pos_x][pos_y]; }
                void create_screen();
                void create_character(std::string a_path, std::string a_sheet_path, int a_x, int a_y);
                CharPC* get_character(int a_char) {return active_chars[a_char];}
                Tile* get_tile_type(uint16_t a_type);
                void shift_char_coordinates(int a_x, int a_y);
                void pan_screen(int dx, int dy);
                void pan_screen(int x_char, int y_char, bool anim);
                void draw_chars();
                int get_world_x();
                int get_world_y();
                ObjectManager* get_object_manager() { return this->m_objects; }
                int get_num_tile_types() { return tile_types.size(); }
                ObjectManager* m_objects;
          private:
                  //Note: For memory reasons, it would be prudent to make this an array of empty pointers
                  //which will be loaded dynamically
                  ScreenPanel* map[10][10];


                  vector<Tile*> tile_types;

                  CharPC* active_chars[MAX_CHARS];
                  int current_chars;
                  int pos_x;
                  int pos_y;
                  ControlKeys char_control[3];
          };


};
#endif
