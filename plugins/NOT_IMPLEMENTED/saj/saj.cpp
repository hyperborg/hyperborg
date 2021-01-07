#include <saj.h>

saj::saj(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SAJ Solar Inverter");
	manifest.insert("domain","saj");
}

saj::~saj()
{
}

void saj::init()
{
}


