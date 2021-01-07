#include <flock.h>

flock::flock(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Flock");
	manifest.insert("domain","flock");
}

flock::~flock()
{
}

void flock::init()
{
}


