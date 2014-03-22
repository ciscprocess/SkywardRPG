#ifndef CHARNPC_H
#define CHARNPC_H
#include <allegro.h>
        
namespace Skyward
{
    class CharNPC
    {
    public:
        CharNPC(int c_x, int c_y, string c_path);
        ~CharNPC();           
               
    private:
        int x;
        int y;
        BITMAP* m_img;
                
    }
}

#endif
