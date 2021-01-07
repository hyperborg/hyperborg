#include <skybeacon.h>

skybeacon::skybeacon(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Skybeacon");
	manifest.insert("domain","skybeacon");
}

skybeacon::~skybeacon()
{
}

void skybeacon::init()
{
}


