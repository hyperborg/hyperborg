#include <fritz.h>

fritz::fritz(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","AVM FRITZ!Box");
	manifest.insert("domain","fritz");
}

fritz::~fritz()
{
}

void fritz::init()
{
}


