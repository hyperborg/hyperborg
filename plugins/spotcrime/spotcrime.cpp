#include <spotcrime.h>

spotcrime::spotcrime(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Spot Crime");
	manifest.insert("domain","spotcrime");
}

spotcrime::~spotcrime()
{
}

void spotcrime::init()
{
}


