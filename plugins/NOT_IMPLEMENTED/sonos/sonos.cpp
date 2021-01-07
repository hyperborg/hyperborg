#include <sonos.h>

sonos::sonos(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sonos");
	manifest.insert("domain","sonos");
}

sonos::~sonos()
{
}

void sonos::init()
{
}

void sonos::async_setup()
{
}


void sonos::async_setup_entry()
{
}


