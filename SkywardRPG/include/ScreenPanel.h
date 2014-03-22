/*
    ScreenPanel.h - this file contains all of the headers for the class ScreenPanel,
    where ScreenPanel represents either a room or a section of outdoors.
*/

#include "Tile.h"

#ifndef SCREENPANEL_H
	#define SCREENPANEL_H

namespace Skyward
{
          class ScreenPanel
          {
          public:
                 ScreenPanel(int x, int y);
                 ~ScreenPanel();
                 static const int TILE_WIDTH = 32;
                 static const int TILE_HEIGHT = 24;
                 void set_shell();
                 void map_tiles();
                 void draw_to_screen();
                 void draw_to_screen(int a_x1, int a_y1, int a_x2, int a_y2);
                 void update_to_screen();
                 void draw_to_panel(BITMAP* a_bmp, int x, int y);
                 int get_traversable(int a_x, int a_y);

          private:
                Tile* m_tile[TILE_HEIGHT][TILE_WIDTH];
                bool m_drawn[TILE_HEIGHT][TILE_WIDTH];
                int m_tile_shell[44][44]; // TEMP
                void load_shell(string a_filename);
                int world_x;
                int world_y;
          };
}
#endif
