#include <worldclock.h>

worldclock::worldclock(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Worldclock");
	manifest.insert("domain","worldclock");
}

worldclock::~worldclock()
{
}

void worldclock::init()
{
}


