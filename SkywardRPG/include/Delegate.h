#ifndef DELEGATE_H
#define DELEGATE_H
#include "EventCapable.h"
#include "LogEventWriter.h"
namespace Skyward
{
    class Delegate
    {
        public:
            Delegate(GenericMemPTR c_address, EventCapable *c_instance);
            virtual ~Delegate();
            Delegate(const Delegate& other);
            void execute();
        protected:
        private:
        GenericMemPTR m_address;
        EventCapable *m_instance;
    };
}
#endif // DELEGATE_H
