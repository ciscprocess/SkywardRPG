/*
  GetTileException.h - this file contains the class GetTileException
*/

#ifndef GET_TILE_EXCEPTION
        #define GET_TILE_EXCEPTION
#include <exception>
#include <string>
using namespace std;

namespace Skyward
{
    namespace Exception
    {
        class GetTileException : public exception
        {
          public:
              GetTileException(string msg) throw() { m_message = msg; }
              ~GetTileException() throw();
              virtual const char* what() throw()
              {
                m_message.insert(0, "An Exception of type GetTileException occured: ");
                return (m_message).c_str();
              }
          private:
              string m_message;
        };
    }
}
#endif
