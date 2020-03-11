#include <hue.h>

hue::hue(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Philips Hue");
	manifest.insert("domain","hue");
}

hue::~hue()
{
}

void hue::init()
{
}

void hue::async_setup()
{
}


void hue::async_setup_entry()
{
}


void hue::async_unload_entry()
{
}


