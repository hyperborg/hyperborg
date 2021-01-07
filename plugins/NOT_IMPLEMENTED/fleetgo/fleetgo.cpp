#include <fleetgo.h>

fleetgo::fleetgo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","FleetGO");
	manifest.insert("domain","fleetgo");
}

fleetgo::~fleetgo()
{
}

void fleetgo::init()
{
}


