#include <lock.h>

lock::lock(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Lock");
	manifest.insert("domain","lock");
}

lock::~lock()
{
}

void lock::init()
{
}

void lock::is_locked()
{
}


void lock::async_setup()
{
}


void lock::async_setup_entry()
{
}


void lock::async_unload_entry()
{
}


void lock::changed_by()
{
}


void lock::code_format()
{
}


void lock::lock()
{
}


void lock::async_lock()
{
}


void lock::unlock()
{
}


void lock::async_unlock()
{
}


void lock::open()
{
}


void lock::async_open()
{
}


void lock::state_attributes()
{
}


void lock::state()
{
}


