#include <ecobee.h>

ecobee::ecobee(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ecobee");
	manifest.insert("domain","ecobee");
}

ecobee::~ecobee()
{
}

void ecobee::init()
{
}

void ecobee::async_setup()
{
}


void ecobee::async_setup_entry()
{
}


void ecobee::__init__()
{
}


void ecobee::update()
{
}


void ecobee::refresh()
{
}


void ecobee::async_unload_entry()
{
}


