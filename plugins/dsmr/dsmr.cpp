#include <dsmr.h>

dsmr::dsmr(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DSMR Slimme Meter");
	manifest.insert("domain","dsmr");
}

dsmr::~dsmr()
{
}

void dsmr::init()
{
}


