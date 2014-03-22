/*
	World.cpp - this file contains the implementation of World.h.
*/
#include <allegro.h>
#include <fstream>
#include "World.h"
#include "ScreenPanel.h"
#include "CharPC.h"
#include "Tile.h"
#include "Globals.h"
#include "ConfigFileReader.h"
#include <string>

using namespace Skyward::Exception;
namespace Skyward
{
    World::World(int x, int y)
    {
          /*
             get the file names of the tile bitmaps
          */

          /*
          ConfigFileReader t_reader("./config/object_definitions.cfg");
          allegro_message("Reader Result: %sg", t_reader.get_next_statement().c_str());
          allegro_message("Param Result: %sg", t_reader.get_current_parameter().c_str());
          allegro_message("Reader Result2: %sg", t_reader.get_next_statement().c_str());
          allegro_message("Attr1 Result: %sg", t_reader.get_current_attribute(0).c_str());
          allegro_message("Attr2 Result: %sg", t_reader.get_current_attribute(1).c_str());
          allegro_message("Attr3 Result: %sg", t_reader.get_current_attribute(2).c_str());
          */
          ifstream infile("./config/tile_definitions.cfg");
          string definition_data;
          getline(infile, definition_data);


          vector<Tile*> temp_tile_types;

          string::size_type pos = definition_data.find("tile_dir_relative", 0);
          string::size_type comma_pos = definition_data.find(",", pos);
          string::size_type semicolon_pos = definition_data.find(";", 0);
          definition_data.erase(semicolon_pos, 1);
          string pat_prefix = definition_data.substr(comma_pos + 2);

          while (infile.good())
          {
              string filename_data = "";

              getline(infile, filename_data);

              if (filename_data.compare("") == 0)
              {
                 myProg->s_log->warning("An empty line was found in the tile definitions file. Skipping.");
                 continue;
              }

              string::size_type comma_pos2 = filename_data.find(",") + 2;

              int index = atoi((filename_data.substr(0, comma_pos2)).c_str());

              string file_name = filename_data.substr(comma_pos2);
              string::size_type semicolon_pos2 = file_name.find(":", 0);
              file_name.erase(semicolon_pos2 - 1);

              file_name.insert(0, pat_prefix);
//              myProg->s_log->info(file_name);

              string::size_type colon_pos = filename_data.find(":", 0);
              string::size_type temp = filename_data.find(";", 0);

              string tile_type = filename_data.substr(colon_pos + 1);

              temp = tile_type.find(";", 0);
              tile_type.erase(temp);

              temp_tile_types.push_back(new Tile(file_name, tile_type, index));
          }

          /*
              now that the bitmap names and types have been retrieved from the config file,
              let us create new Tile instances using these data.
          */


		  //Tile* temp_tile_types[50];
		  /*
          for (int iterator = 0; paths[iterator].compare("") != 0; iterator++)
          {
             temp_tile_types.push_back(new Tile(paths[iterator], types[iterator]));
          }
          */
          for (uint16_t for_index = 0; for_index < temp_tile_types.size(); for_index++)
          {
              this->tile_types.push_back(temp_tile_types[for_index]);
          }

          this->pos_x = x;
          this->pos_y = y;

          for (int for_index = 0; for_index < 3; for_index++)
          {
              this->char_control[for_index] = CHAR_STATIC;
          }

          current_chars = 0;

          this->m_objects = new ObjectManager(this);
    }

    int World::get_world_x()
    {
        return this->pos_x;
    }

    int World::get_world_y()
    {
        return this->pos_y;
    }

    void World::pan_screen(int x_char, int y_char, bool anim)
    {
        int dx = 0;
        int dy = 0;
        try
        {
            if (x_char >= ((ScreenPanel::TILE_WIDTH) * 20))
            {
               this->pos_x++;
               dx = 1;
               create_screen();

               delete this->map[this->pos_x - 1][this->pos_y];

               this->get_screen()->draw_to_screen();


               CharPC* chare = this->get_character(0);

               shift_char_coordinates(-1 * (chare->get_x() - 1), 0);

            }

            else if (x_char < 0)
            {
               this->pos_x--;
               dx = -1;
               create_screen();
               delete this->map[this->pos_x + 1][this->pos_y];
               this->get_screen()->draw_to_screen();

               //CharPC* chare = this->get_character(0);
               shift_char_coordinates(600, 0);
            }

            else if (y_char >= ((ScreenPanel::TILE_HEIGHT) * 20))
            {
               this->pos_y++;
               dy = 1;
               create_screen();
               this->get_screen()->draw_to_screen();

               CharPC* chare = this->get_character(0);
               shift_char_coordinates(0, -1 * (chare->get_y() - 1));
               delete this->map[this->pos_x][this->pos_y - 1];
            }

            else if (y_char < 0)
            {
               this->pos_y--;
               dy = -1;
               create_screen();
               this->get_screen()->draw_to_screen();

               //CharPC* chare = this->get_character(0);
               shift_char_coordinates(0, 440);
               delete this->map[this->pos_x][this->pos_y + 1];
            }
            else
            {

            }
        }
        catch (ConfigFileException* ex)
        {
              this->pos_x += -dx;
              this->pos_y += -dy;
              myProg->s_log->error(ex->what());
        }
    }

    World::~World()
    {

    }

    void World::create_screen()
    {

         this->map[this->pos_x][this->pos_y] = new ScreenPanel(this->pos_x, this->pos_y);
         this->m_objects->init_objects();
    }

    void World::shift_char_coordinates(int a_x, int a_y)
    {
         for (int for_index = 0; for_index < current_chars; for_index++)
         {
             this->active_chars[for_index]->inc_coordinates(a_x, a_y);
         }
    }

    void World::create_character(std::string a_path, string a_sheet_path, int a_x, int a_y)
    {
         BITMAP* s_bitmap = load_bitmap(a_path.c_str(), NULL);
         BITMAP* sheet_bitmap = load_bitmap(a_sheet_path.c_str(), NULL);
         this->active_chars[current_chars] = new CharPC(s_bitmap, sheet_bitmap, a_x, a_y);
         current_chars++;
    }

    Tile* World::get_tile_type(uint16_t a_type)
    {
      if (a_type >= 0 && a_type < tile_types.size()) return this->tile_types[a_type];
      else
          {
            throw new GetTileException ("get_tile_type failed because an index was out of range.");
          }
      }

    void World::draw_chars()
    {
         for (int for_index = 0; for_index < current_chars; for_index++)
         {
             this->active_chars[for_index]->draw();
             if (key[KEY_UP] || key[KEY_DOWN] || key[KEY_LEFT] || key[KEY_RIGHT]) this->active_chars[for_index]->iterate_animation(1);
         }
    }
}
