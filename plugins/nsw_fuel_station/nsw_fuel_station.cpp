#include <nsw_fuel_station.h>

nsw_fuel_station::nsw_fuel_station(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","NSW Fuel Station Price");
	manifest.insert("domain","nsw_fuel_station");
}

nsw_fuel_station::~nsw_fuel_station()
{
}

void nsw_fuel_station::init()
{
}


