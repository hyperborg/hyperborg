#include <nextbus.h>

nextbus::nextbus(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","NextBus");
	manifest.insert("domain","nextbus");
}

nextbus::~nextbus()
{
}

void nextbus::init()
{
}


