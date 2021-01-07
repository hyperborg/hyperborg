#include <coronavirus.h>

coronavirus::coronavirus(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Coronavirus (COVID-19)");
	manifest.insert("domain","coronavirus");
}

coronavirus::~coronavirus()
{
}

void coronavirus::init()
{
}

void coronavirus::async_setup()
{
}


void coronavirus::async_setup_entry()
{
}


void coronavirus::_async_migrator()
{
}


void coronavirus::async_unload_entry()
{
}


void coronavirus::get_coordinator()
{
}


void coronavirus::async_get_cases()
{
}


