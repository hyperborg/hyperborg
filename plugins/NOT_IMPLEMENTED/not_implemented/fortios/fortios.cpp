#include <fortios.h>

fortios::fortios(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Home Assistant Device Tracker to support FortiOS");
	manifest.insert("domain","fortios");
}

fortios::~fortios()
{
}

void fortios::init()
{
}


