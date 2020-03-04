#include <sensor.h>

sensor::sensor()
{
    	manifest.insert("domain","sensor");
	manifest.insert("name","Sensor");
}

sensor::~sensor()
{
}

void sensor:: async_setup()
{
}


void sensor:: async_setup_entry()
{
}


void sensor:: async_unload_entry()
{
}


