#include <eq3btsmart.h>

eq3btsmart::eq3btsmart(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","EQ3 Bluetooth Smart Thermostats");
	manifest.insert("domain","eq3btsmart");
}

eq3btsmart::~eq3btsmart()
{
}

void eq3btsmart::init()
{
}


