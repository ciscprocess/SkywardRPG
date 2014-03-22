#ifndef LOGEVENTWRITER_H
#define LOGEVENTWRITER_H
#include <string>
#include "EventCapable.h"

using namespace std;

namespace Skyward
{
    class LogEventWriter : public EventCapable
    {
        public:
            LogEventWriter(string c_message);
            virtual ~LogEventWriter();
            void write_message();
        protected:
        private:
            string m_message;
    };
}

#endif // LOGEVENTWRITER_H
