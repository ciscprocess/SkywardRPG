#ifndef WORD_H
#define WORD_H
#include <string>
using namespace std;

namespace Skyward
{
    class Word
    {
        public:
            Word(string c_name, string c_def, string c_type) { m_name = c_name; m_def = c_def; m_type = c_type; }

            string m_name;
            string m_def;
            string m_type;
        protected:
        private:
    };
}

#endif // WORD_H
