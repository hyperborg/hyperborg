#include <ecovacs.h>

ecovacs::ecovacs(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ecovacs");
	manifest.insert("domain","ecovacs");
}

ecovacs::~ecovacs()
{
}

void ecovacs::init()
{
}

void ecovacs::setup()
{
}


void ecovacs::stop()
{
}


