#ifndef CONFIGFILEREADER_H
#define CONFIGFILEREADER_H
#include <string>
#include <fstream>
using namespace std;
namespace Skyward
{
    class ConfigFileReader
    {
        public:
            ConfigFileReader(string c_path);
            virtual ~ConfigFileReader();
            void open_config(string a_path);
            void reset_position();
            string get_next_line();
            string get_next_statement();
            string get_current_parameter();
            string get_current_attribute(int a_index);
            bool is_reader_good() { return m_infile_line->good() && m_infile_statement->good(); }
        protected:
        private:
            ifstream* m_infile_line;
            ifstream* m_infile_statement;
            string m_current_line;
            string m_current_statement;
    };
}
#endif // CONFIGFILEREADER_H
