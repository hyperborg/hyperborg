#include <openhome.h>

openhome::openhome(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Linn / OpenHome");
	manifest.insert("domain","openhome");
}

openhome::~openhome()
{
}

void openhome::init()
{
}


