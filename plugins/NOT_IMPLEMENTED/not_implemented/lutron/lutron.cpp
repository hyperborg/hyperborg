#include <lutron.h>

lutron::lutron(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Lutron");
	manifest.insert("domain","lutron");
}

lutron::~lutron()
{
}

void lutron::init()
{
}

void lutron::setup()
{
}


void lutron::__init__()
{
}


void lutron::async_added_to_hass()
{
}


void lutron::_update_callback()
{
}


void lutron::should_poll()
{
}


void lutron::button_callback()
{
}


