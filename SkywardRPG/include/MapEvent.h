#ifndef MAPEVENT_H
#define MAPEVENT_H
#define DONTLOAD

#include "EventCapable.h"
#include "Delegate.h"
#include "MapObject.h"

namespace Skyward
{
    class MapObject ;
    class MapEvent
    {
        public:
            MapEvent(MapObject *c_parent);
            virtual ~MapEvent();
            Delegate *on_trigger;
            void check();
            virtual void set_trigger(Delegate *c_on_trigger);
            MapObject* get_parent() { return this->parent; }
        protected:
            MapObject *parent;
            bool m_triggered;
            virtual void check_internal();
    };
}
#endif // MAPEVENT_H
