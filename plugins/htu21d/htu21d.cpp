#include <htu21d.h>

htu21d::htu21d(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","HTU21D(F) Sensor");
	manifest.insert("domain","htu21d");
}

htu21d::~htu21d()
{
}

void htu21d::init()
{
}


