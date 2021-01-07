#include <eddystone_temperature.h>

eddystone_temperature::eddystone_temperature(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Eddystone");
	manifest.insert("domain","eddystone_temperature");
}

eddystone_temperature::~eddystone_temperature()
{
}

void eddystone_temperature::init()
{
}


