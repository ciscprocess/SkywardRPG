#ifndef AUDIOEXCEPTION_H
#define AUDIOEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

namespace Skyward
{
    namespace Exception
    {
        class AudioException : public exception
        {
          public:
              AudioException(string msg) throw() { m_message = msg; }
              ~AudioException() throw();
              virtual const char* what() throw()
              {
                m_message.insert(0, "An Exception of type AudioException occured: ");
                return (m_message).c_str();
              }
          private:
              string m_message;
        };
    }
};
#endif // AUDIOEXCEPTION_H
