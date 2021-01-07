#include <aprs.h>

aprs::aprs(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","APRS");
	manifest.insert("domain","aprs");
}

aprs::~aprs()
{
}

void aprs::init()
{
}


