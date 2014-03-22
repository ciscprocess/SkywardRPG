/*
  Name: ConfigParser.h
  Copyright: none
  Author: Nathan Korzekwa
  Date: 15/06/10 21:20
  Description: Reads in global application settings from a file.
*/
#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H
#include <string>
using namespace std;
namespace Skyward
{
    class ConfigParser
    {
        public:
            ConfigParser(string c_file_path);
            virtual ~ConfigParser();
            string get_file() { return m_file; }
            void set_file(string val) { m_file = val; }
            string get_value(string a_name, int a_level);
        protected:
        private:
             string m_file;
    };

}

#endif // CONFIGPARSER_H
