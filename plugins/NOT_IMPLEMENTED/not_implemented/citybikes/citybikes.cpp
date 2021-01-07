#include <citybikes.h>

citybikes::citybikes(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","CityBikes");
	manifest.insert("domain","citybikes");
}

citybikes::~citybikes()
{
}

void citybikes::init()
{
}


