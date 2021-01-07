#include <generic_thermostat.h>

generic_thermostat::generic_thermostat(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Generic Thermostat");
	manifest.insert("domain","generic_thermostat");
}

generic_thermostat::~generic_thermostat()
{
}

void generic_thermostat::init()
{
}


