#include <yweather.h>

yweather::yweather(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Yahoo Weather");
	manifest.insert("domain","yweather");
}

yweather::~yweather()
{
}

void yweather::init()
{
}


