#include <gpsd.h>

gpsd::gpsd(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","GPSD");
	manifest.insert("domain","gpsd");
}

gpsd::~gpsd()
{
}

void gpsd::init()
{
}


