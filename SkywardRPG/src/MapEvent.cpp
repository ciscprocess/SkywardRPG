#include "MapEvent.h"

#include "Globals.h"
#include "Delegate.h"
namespace Skyward
{
    MapEvent::MapEvent(MapObject *c_parent)
    {
        //myProg->s_log->warning("Base Event type has been created. Normally, this should not happen; check your code.");
        World *t_world = myProg->get_world();
        this->parent = c_parent;
        t_world->m_objects->add_event(this);
        m_triggered = false;
    }

    void MapEvent::set_trigger(Delegate *c_on_trigger)
    {
         on_trigger = c_on_trigger;
    }

    void MapEvent::check()
    {
         if (parent->get_x() > -1)
            check_internal();
    }

    void MapEvent::check_internal()
    {
         myProg->s_log->warning("No stars shine upon the Doomstone.");
    }
}

MapEvent::~MapEvent()
{
    //dtor
}
