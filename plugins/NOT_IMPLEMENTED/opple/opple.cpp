#include <opple.h>

opple::opple(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Opple");
	manifest.insert("domain","opple");
}

opple::~opple()
{
}

void opple::init()
{
}


