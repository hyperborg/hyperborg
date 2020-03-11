#include <mhz19.h>

mhz19::mhz19(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MH-Z19 CO2 Sensor");
	manifest.insert("domain","mhz19");
}

mhz19::~mhz19()
{
}

void mhz19::init()
{
}


