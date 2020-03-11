#include <oem.h>

oem::oem(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OpenEnergyMonitor WiFi Thermostat");
	manifest.insert("domain","oem");
}

oem::~oem()
{
}

void oem::init()
{
}


