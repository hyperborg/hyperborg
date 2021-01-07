#include <sensor.h>

sensor::sensor(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sensor");
	manifest.insert("domain","sensor");
}

sensor::~sensor()
{
}

void sensor::init()
{
}

void sensor::async_setup()
{
}


void sensor::async_setup_entry()
{
}


void sensor::async_unload_entry()
{
}


