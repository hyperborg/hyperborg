#include <tof.h>

tof::tof(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Time of Flight");
	manifest.insert("domain","tof");
}

tof::~tof()
{
}

void tof::init()
{
}


