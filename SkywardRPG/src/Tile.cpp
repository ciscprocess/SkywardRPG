/*
	Tile.cpp - this file contains the implementation of Tile.h.
*/

#include "Globals.h"
#include <string>
#define STRING_TO_TYPE(type) 
using namespace std;
namespace Skyward
{
          Tile::Tile(string c_path, string c_tile_type, int c_index)
          {
              TileType type1;
              if (c_tile_type.compare("SOLID_GROUND") == 0) type1 = SOLID_GROUND;
              else if (c_tile_type.compare("WALL") == 0) type1 = WALL;
              else if (c_tile_type.compare("WATER") == 0) type1 = WATER;
              else 
              {
                   type1 = SOLID_GROUND;
                   myProg->s_log->warning("Invalid TileType configuration data. Check your tile_definitions.cfg");
              } 
               m_image = load_bitmap(c_path.c_str(), 0);  
               if (!m_image) myProg->s_log->fatal("Could not load bitmap");
               this->type = type1;
               this->m_path = c_path;
               this->is_primitive = false;
               this->walkable = true;
               this->tile_index = c_index;
          }
          Tile::Tile(bool c_prim)
          {
              this->m_path = "I iz fogey";   
              //allegro_message("In BOOL?????");
          }
          Tile::~Tile()
          {
                 clear_bitmap(m_image);
                 delete m_image;   
          }        
          
}

