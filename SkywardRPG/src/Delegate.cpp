#include "Delegate.h"
#include "Globals.h"
#include "LogEventWriter.h"
using namespace Skyward;
Delegate::Delegate(GenericMemPTR c_address, EventCapable *c_instance)
{
    m_address = c_address;
    m_instance = c_instance;
}

Delegate::~Delegate()
{
    //dtor
}

void Delegate::execute()
{
    (this->m_instance->*m_address)();
}

Delegate::Delegate(const Delegate& other)
{
    //copy ctor
}
