#include "LogEventWriter.h"
#include "Globals.h"
using namespace Skyward;
LogEventWriter::LogEventWriter(string c_message)
{
    m_message = c_message;
}

void LogEventWriter::write_message()
{
    myProg->s_log->warning(m_message);
}

LogEventWriter::~LogEventWriter()
{
    //dtor
}
