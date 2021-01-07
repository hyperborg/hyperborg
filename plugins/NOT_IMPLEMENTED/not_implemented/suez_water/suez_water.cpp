#include <suez_water.h>

suez_water::suez_water(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Suez Water");
	manifest.insert("domain","suez_water");
}

suez_water::~suez_water()
{
}

void suez_water::init()
{
}


