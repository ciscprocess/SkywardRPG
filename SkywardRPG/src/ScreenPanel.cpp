/*
	ScreenPanel.cpp - this file contains the implementation of ScreenPanel.h.
*/

#include "Globals.h"
#include <fstream>
extern BITMAP* buffer;
using namespace std;
using namespace Skyward::Exception;
namespace Skyward
{
    ScreenPanel::ScreenPanel(int x, int y)
    {
         try
         {
             this->world_x = x;
             this->world_y = y;
             load_shell("./config/map_shells.cfg");
             this->map_tiles();
         }
         catch(GetTileException* ex)
         {
             allegro_message(ex->what());
             myProg->s_log->fatal(ex->what());
         }
    }

    ScreenPanel::~ScreenPanel()
    {
         delete m_tile_shell;
    }

    void ScreenPanel::set_shell()
    {

    }

    void ScreenPanel::map_tiles()
    {
      World* testWorld = myProg->get_world();
      if (!m_tile_shell)
      {
         myProg->s_log->fatal("The tile shell is empty, aborting.");
      }

      for (int for_index = 0; for_index < TILE_HEIGHT; for_index++)
      {
          for (int for_index_2 = 0; for_index_2 < TILE_WIDTH; for_index_2++)
          {
              string type = testWorld->get_tile_type(0)->get_path();
              //if (this->m_tile_shell[for_index][for_index_2] > 10) allegro_message("Adr: %d at (%d,%d)", this->m_tile_shell[for_index][for_index_2], for_index_2, for_index);
              if (this->m_tile_shell[for_index][for_index_2] >= testWorld->get_num_tile_types())
                  throw new GetTileException("An invalid tile type number was found in the map shell. Check your tile definitions file.");
              this->m_tile[for_index][for_index_2] = testWorld->get_tile_type(this->m_tile_shell[for_index][for_index_2]);//this->m_tile_shell[for_index][for_index_2]);
          }
      }
//      myProg->s_log->info("Leaving map_tiles()!");
    }

    void ScreenPanel::draw_to_screen()
     {
         for (int for_index = 0; for_index < TILE_HEIGHT; for_index++)
          {
              for (int for_index_2 = 0; for_index_2 < TILE_WIDTH; for_index_2++)
              {
                  //int t_size = sizeof(*m_tile[for_index][for_index_2]);
                  if (!m_tile[for_index][for_index_2])
                  {
                     myProg->s_log->fatal("One of the ScreenPanel tiles was undefined. This is a serious internal error. Aborting");
                  }
                  BITMAP* bmp = this->m_tile[for_index][for_index_2]->get_image();
                  if (!this->m_tile[for_index][for_index_2]->get_image()) myProg->s_log->fatal("Invalid Bitmap");
                  int var = is_memory_bitmap(bmp);
                  if (var != 1) myProg->s_log->fatal("Could not get bitmap");
                  stretch_blit(bmp, buffer, 0, 0, bmp->w, bmp->h, (for_index_2 * 20), (for_index * 20), 20, 20);
              }
          }
     }

     void ScreenPanel::draw_to_screen(int a_x1, int a_y1, int a_x2, int a_y2)
     {
          int x1 = (a_x1 < a_x2) ? a_x1 : a_x2;
          int x2 = (a_x1 > a_x2) ? a_x1 : a_x2;

          int y1 = (a_y1 < a_y2) ? a_y1 : a_y2;
          int y2 = (a_y1 > a_y2) ? a_y1 : a_y2;

          int _even_div = x1 - (x1 % 20);
          int tx1 = (_even_div / 20) - 1;

          _even_div = x2 - (x2 % 20);
          int tx2 = (_even_div / 20) + 1;

          _even_div = y1 - (y1 % 20);
          int ty1 = (_even_div / 20) - 1;

          _even_div = y2 - (y2 % 20);
          int ty2 = (_even_div / 20) + 1;

         //allegro drawing code
         for (int for_index = ty1; for_index <= ty2; for_index++)
          {
              for (int for_index_2 = tx1; for_index_2 <= tx2; for_index_2++)
              {
                  if (!m_tile[for_index][for_index_2] && (for_index >= 0 && for_index_2 >= 0) && (for_index > TILE_HEIGHT + 3 && for_index_2 > TILE_WIDTH + 3))
                  {
                     myProg->s_log->fatal("One of the ScreenPanel tiles was undefined. This is a serious internal error. Aborting");
                  }
                  if (for_index >= 0 && for_index_2 >= 0 && (for_index < TILE_HEIGHT && for_index_2 < TILE_WIDTH))
                      stretch_blit(this->m_tile[for_index][for_index_2]->get_image(), buffer, 0, 0, this->m_tile[for_index][for_index_2]->get_image()->w, this->m_tile[for_index][for_index_2]->get_image()->h, (for_index_2 * 20), (for_index * 20), 20, 20);
              }
          }
     }

     void ScreenPanel::load_shell(string a_filename)
     {
          bool found_header = false;
          ifstream infile(a_filename.c_str());
          string needed_map_header = "";
          while (infile.good())
          {
              string config_data;
              getline(infile, config_data);
              char x_buffer[5];
              char y_buffer[5];

              sprintf(x_buffer, "%d", this->world_x);
              sprintf(y_buffer, "%d", this->world_y);

              needed_map_header = "m(,):";

              string x_str = x_buffer;
              needed_map_header.insert(2, x_str);
              string y_str = y_buffer;
              needed_map_header.insert(3 + x_str.size(), y_str);

              if (config_data.compare(needed_map_header) == 0)
              {
                 found_header = true;
                 break;
              }

          }
          if (!found_header)
          {
            string messageer = needed_map_header;
            messageer.insert(0, "Could not find proper map shell with header: ");
            throw new ConfigFileException(messageer);
          }
          int row_iterator = 0;

          //char map_row[TILE_WIDTH];

          while (infile.good())
          {
              string s_map_row;
              getline(infile, s_map_row);
              if (s_map_row.compare("") == 0)
              {
                 myProg->s_log->warning("An empty line was found in the map shell file. Skipping.");
                 continue;
              }

              if (s_map_row[0] == 'm')
              {
                 infile.close();
                 break;
              }
              uint16_t alterIter = 0;
              uint16_t iteration_count = 0;
              uint16_t _comma_pos_prior = s_map_row.find("[",0);
              uint16_t _comma_pos_latter = (s_map_row.find(",",_comma_pos_prior + 1) == -1) ? s_map_row.find("[",_comma_pos_prior + 1) : s_map_row.find(",",_comma_pos_prior + 1);
              while (_comma_pos_latter < s_map_row.length())
              {
                  string tile_num = s_map_row.substr(_comma_pos_prior + 1, (_comma_pos_latter - _comma_pos_prior) - 1);
                  if (row_iterator < TILE_HEIGHT)
                  {
                      this->m_tile_shell[row_iterator][alterIter] = atoi(tile_num.c_str());

                      _comma_pos_prior = _comma_pos_latter; //(s_map_row.find(",",_comma_pos_latter+1) == -1) ? s_map_row.find("]",_comma_pos_latter+1) : s_map_row.find(",",_comma_pos_latter+1);
                      _comma_pos_latter = (s_map_row.find(",",_comma_pos_prior + 1) == -1) ? s_map_row.find("]",_comma_pos_prior + 1) : s_map_row.find(",",_comma_pos_prior + 1);
                      iteration_count++;
                  }
                  alterIter++;
              }
              if (alterIter < TILE_WIDTH - 1)
              {
                  myProg->s_log->error("Not enough tiles defined in shell for one row. Using default value of 0 for all missing.");
              }
              row_iterator++;
          }
          infile.close();
     }

     int ScreenPanel::get_traversable(int a_x, int a_y)
     {
       if (myProg->get_world()->get_object_manager()->get_traversability(a_x, a_y) == 0)
            return 0;
       if (a_x < 0) return -1;
       else if (a_x > (TILE_WIDTH)*20) return -1;
       if (a_y < 0) return -1;
       else if (a_y > (TILE_HEIGHT)*20) return -1;
       else if ((a_y / 20) < TILE_HEIGHT &&  (a_x / 20) < TILE_WIDTH)
       {
           if (m_tile[a_y / 20][a_x / 20]->get_type() == WALL)
           {
               return 0;
           }
           else if (m_tile[a_y / 20][a_x / 20]->get_type() != WALL)
           {
               return 1;
           }
       }
       return 1;
     }

     void ScreenPanel::update_to_screen()
     {

     }
}
