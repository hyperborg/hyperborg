#include <switch.h>

switch::switch(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Switch");
	manifest.insert("domain","switch");
}

switch::~switch()
{
}

void switch::init()
{
}

void switch::is_on()
{
}


void switch::async_setup()
{
}


void switch::async_setup_entry()
{
}


void switch::async_unload_entry()
{
}


void switch::current_power_w()
{
}


void switch::today_energy_kwh()
{
}


void switch::is_standby()
{
}


void switch::state_attributes()
{
}


void switch::device_class()
{
}


