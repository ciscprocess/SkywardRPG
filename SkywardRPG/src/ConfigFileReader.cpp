#include "Globals.h"
#include "ConfigFileReader.h"
#include "ConfigFileException.h"
#include <vector>


using namespace std;
using namespace Skyward;
using namespace Exception;
ConfigFileReader::ConfigFileReader(string c_path)
{
    this->open_config(c_path);
}

ConfigFileReader::~ConfigFileReader()
{
    //dtor
}

void ConfigFileReader::reset_position()
{
    m_infile_statement->seekg(0, ios::beg);
    m_infile_line->seekg(0, ios::beg);
}

void ConfigFileReader::open_config(string a_path)
{
    this->m_infile_line = new ifstream(a_path.c_str());
    this->m_infile_statement = new ifstream(a_path.c_str());
}

string ConfigFileReader::get_next_line()
{
    if (!m_infile_line->is_open())
    {
        throw new ConfigFileException("Error in accessing config file");
    }
    string config_data;
    getline((*m_infile_line), config_data);
    this->m_current_line = config_data;
    return this->m_current_line;
}

string ConfigFileReader::get_next_statement()
{
    if (!m_infile_statement->is_open())
    {
        throw new ConfigFileException("Error in accessing config file");
    }

    char t_data[2048];

    m_infile_statement->get(t_data, 2048, ';');

    string tt_data = t_data;
    m_current_statement = tt_data;
    m_infile_statement->get();
    return tt_data;
}

string ConfigFileReader::get_current_parameter()
{
    int t_first = m_current_statement.find(':', 0);
    string _param = m_current_statement.substr(0, t_first);
    return _param;
}

string ConfigFileReader::get_current_attribute(int a_index)
{
    //const char* _char22 = m_current_statement.c_str();
    int t_first = m_current_statement.find(':', 0);
    int _end_count = m_current_statement.size() - t_first;
    string _attrs = m_current_statement.substr(t_first, _end_count);
    const char* _char = _attrs.c_str();
    int c_count = 0;
    vector<int> positions;
    positions.push_back(0);
    for (unsigned int for_index = 0; for_index < _attrs.size(); for_index++)
    {
        if (_char[for_index] == ',')
        {
            c_count++;
            positions.push_back(for_index);
        }
    }
    int attr_count = c_count + 1;
    if (a_index > (attr_count - 1))
    {
        myProg->s_log->error("get_current_attribute a_index > size in config file. Returning empty string.");
        string retv("");
        return retv;
    }

    if (a_index == attr_count - 2) _end_count = _attrs.size() - positions[a_index];
    string ret_attr = _attrs.substr(positions[a_index] + 1, positions[a_index + 1] - positions[a_index] - 1);
    return ret_attr;
}
