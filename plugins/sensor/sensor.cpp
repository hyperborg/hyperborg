#include <sensor.h>

sensor::sensor()
{
    	manifest.insert("name","Sensor");
	manifest.insert("domain","sensor");
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


