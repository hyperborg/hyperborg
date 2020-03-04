#include <binary_sensor.h>

binary_sensor::binary_sensor()
{
    	manifest.insert("domain","binary_sensor");
	manifest.insert("name","Binary Sensor");
}

binary_sensor::~binary_sensor()
{
}

void binary_sensor:: async_setup()
{
}


void binary_sensor:: async_setup_entry()
{
}


void binary_sensor:: async_unload_entry()
{
}


void binary_sensor::is_on()
{
}


void binary_sensor::state()
{
}


void binary_sensor::device_class()
{
}


