/*
  Contains the exception headers ConfigFileException
*/

#ifndef CONFIG_FILE_EXCEPTION
        #define CONFIG_FILE_EXCEPTION
#include <exception>
#include <string>
using namespace std;

namespace Skyward
{
    namespace Exception
    {
         class ConfigFileException : public exception
        {
          public:
              ConfigFileException(string msg) throw() { m_message = msg; }
              ~ConfigFileException() throw();
              virtual const char* what() throw()
              {
                m_message.insert(0, "An Exception of type ConfigFileException occured: ");
                return (m_message).c_str();
              }
          private:
              string m_message;
        };
    }
}
#endif
