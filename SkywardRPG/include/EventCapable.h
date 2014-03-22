#ifndef EVENTCAPABLE_H
#define EVENTCAPABLE_H

namespace Skyward
{
    class EventCapable
    {
        public:
            EventCapable();
            void null_function();
        protected:
        private:
        //virtual void abstraction() = 0;
    };
}
typedef void (Skyward::EventCapable::*GenericMemPTR)();
#endif // EVENTCAPABLE_H
