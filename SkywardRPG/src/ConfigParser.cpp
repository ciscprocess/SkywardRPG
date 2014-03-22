#include "ConfigParser.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;
namespace Skyward
{
    ConfigParser::ConfigParser(string c_file_path)
    {
        this->m_file = c_file_path;
    }

    string ConfigParser::get_value(string a_name, int a_level)
    {
        ifstream infile(a_name.c_str());
        vector<string> definition_data;
        while (infile.good())
        {
            string _temp_data;
            getline(infile, _temp_data);
            definition_data.push_back(_temp_data);
        }

        string param_name = definition_data[0].substr(0, 1);

    }

    ConfigParser::~ConfigParser()
    {

    }
}

