#ifndef FACEKEYEVENT_H
#define FACEKEYEVENT_H


#include "MapObject.h"
#include "MapEvent.h"

namespace Skyward
{

    class FaceKeyEvent : public MapEvent
    {
        public:
            FaceKeyEvent(MapObject *c_parent) : MapEvent(c_parent) { }
            virtual ~FaceKeyEvent();
        protected:
            virtual void check_internal();
        private:
    };
}


#endif // FACEKEYEVENT_H
