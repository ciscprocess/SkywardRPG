/*
    Logger.h - this file contains all of the headers for the class Logger,
    where Logger represents a log writer.
*/
#include <allegro.h>
#include <string>
#include <fstream>
#ifndef LOGGER_H
        #define LOGGER_H
using namespace std;
namespace Skyward
{
    class Logger
    {
    public:
        Logger();
        void info(string msg);
        void warning(string msg);
        void error(string msg);
        void fatal(string msg);
        static string ReadFile(string filename);
        static void WriteFile(string filename, string msg); 
        
    private:

    };
}

#endif
