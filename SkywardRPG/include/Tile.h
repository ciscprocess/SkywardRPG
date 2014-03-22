/*
    Tile.h - this file contains all of the headers for the class Tile,
    where Tile represents a 20px*20px section of ground
*/


#include "allegro.h"  
#include <string>
using namespace std;
#ifndef TILE_H
        #define TILE_H
       
namespace Skyward
{
    enum TileType {SOLID_GROUND, WATER, WALL}; 
    class Tile
    {
    public:
         Tile(string c_path, TileType c_tile_type);
         Tile(string c_path, string c_tile_type, int c_index);
         Tile(bool c_prim);
         ~Tile();
         BITMAP* get_image() { if (!m_image) allegro_message("Could not load bitmap"); return m_image; }
         string get_path() { return m_path; }
         TileType get_type() { return this->type; }
         int get_index() { return this->tile_index; }
         //TileType type;
    private:
         int tile_index;
         string m_path;
         BITMAP* m_image;
         bool is_primitive;
         bool walkable;
         TileType type;
                                     
    };   
}
#endif
