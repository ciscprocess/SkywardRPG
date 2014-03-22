#include <fstream>
#include <string>
#include <time.h>
#include "Logger.h"
#define _LOG_PATH "./StdOut.log"

using namespace Skyward;
using namespace std;

Logger::Logger()
{
    const time_t timer = time(NULL);
    string _time = ctime(&timer);
    _time.insert(0, "Starting Skyward Reborn at [");
    
    string::size_type loc = _time.find( "\n", 0 );
    if (loc != string::npos) _time.erase(loc);
    
    _time.append(1, ']');
    _time.append("\n");
    WriteFile(_LOG_PATH, _time);

}

string Logger::ReadFile(string filename) 
{
    string msg;
    ifstream infile(filename.c_str());
    infile >> msg;
    return msg;
}    

void Logger::WriteFile(string filename, string msg)
{
  ofstream outfile;
  outfile.open(filename.c_str(), ios::app);
  outfile << msg.c_str();
  outfile.close();
}

void Logger::info(string msg)
{
    const time_t timer = time(NULL);
    string _time = ctime(&timer);
    _time.insert(0, "[");
    _time.insert(0, "(INFO) ");
    string::size_type loc = _time.find( "\n", 0 );
    if (loc != string::npos) _time.erase(loc);
    _time.append(1, ']');
    _time.append(": ");
    this->WriteFile(_LOG_PATH, _time);
    msg.append("\n");
    this->WriteFile(_LOG_PATH, msg);
}

void Logger::warning(string msg)
{
    const time_t timer = time(NULL);
    string _time = ctime(&timer);
    _time.insert(0, "[");
    _time.insert(0, "(WARNING) ");
    string::size_type loc = _time.find( "\n", 0 );
    if (loc != string::npos) _time.erase(loc);
    _time.append(1, ']');
    _time.append(": ");
    this->WriteFile(_LOG_PATH, _time);
    msg.append("\n");
    this->WriteFile(_LOG_PATH, msg);
}

void Logger::error(string msg)
{
    const time_t timer = time(NULL);
    string _time = ctime(&timer);
    _time.insert(0, "[");
    _time.insert(0, "(ERROR) ");
    string::size_type loc = _time.find( "\n", 0 );
    if (loc != string::npos) _time.erase(loc);
    _time.append(1, ']');
    _time.append(": ");
    this->WriteFile(_LOG_PATH, _time);
    msg.append("\n");
    this->WriteFile(_LOG_PATH, msg);
}

void Logger::fatal(string msg)
{
    const time_t timer = time(NULL);
    string _time = ctime(&timer);
    _time.insert(0, "[");
    _time.insert(0, "(FATAL) ");
    string::size_type loc = _time.find( "\n", 0 );
    if (loc != string::npos) _time.erase(loc);
    _time.append(1, ']');
    _time.append(": ");
    this->WriteFile(_LOG_PATH, _time);
    msg.append("\n");
    this->WriteFile(_LOG_PATH, msg);
    exit(-1);
}
