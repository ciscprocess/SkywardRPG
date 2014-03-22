#include "FaceKeyEvent.h"
#include "Globals.h"
#include <math.h>
using namespace Skyward;


FaceKeyEvent::~FaceKeyEvent()
{
    //dtor
}


void FaceKeyEvent::check_internal()
{
    CharPC *_t_char = myProg->get_world()->get_character(0);
    if (fabs(_t_char->get_x() - this->parent->get_x()) < this->parent->get_width() + 4 && fabs(_t_char->get_y() - this->parent->get_y()) < this->parent->get_width() + 4)
    {
        if (key[KEY_SPACE])
        {
            this->on_trigger->execute();
            //allegro_message("Woahhhw222");
        }
    }

}

