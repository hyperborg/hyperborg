#include <comed_hourly_pricing.h>

comed_hourly_pricing::comed_hourly_pricing(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ComEd Hourly Pricing");
	manifest.insert("domain","comed_hourly_pricing");
}

comed_hourly_pricing::~comed_hourly_pricing()
{
}

void comed_hourly_pricing::init()
{
}


