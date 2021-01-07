#include <opnsense.h>

opnsense::opnsense(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OPNSense");
	manifest.insert("domain","opnsense");
}

opnsense::~opnsense()
{
}

void opnsense::init()
{
}

void opnsense::setup()
{
}


