#include <discovery.h>

discovery::discovery(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Discovery");
	manifest.insert("domain","discovery");
}

discovery::~discovery()
{
}

void discovery::init()
{
}

void discovery::async_setup()
{
}


void discovery::new_service_found()
{
}


void discovery::scan_devices()
{
}


void discovery::schedule_first()
{
}


void discovery::_discover()
{
}


