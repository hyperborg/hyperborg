#include <thermoworks_smoke.h>

thermoworks_smoke::thermoworks_smoke(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ThermoWorks Smoke");
	manifest.insert("domain","thermoworks_smoke");
}

thermoworks_smoke::~thermoworks_smoke()
{
}

void thermoworks_smoke::init()
{
}


