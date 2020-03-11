#include <lifx.h>

lifx::lifx(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LIFX");
	manifest.insert("domain","lifx");
}

lifx::~lifx()
{
}

void lifx::init()
{
}

void lifx::async_setup()
{
}


void lifx::async_setup_entry()
{
}


void lifx::async_unload_entry()
{
}


