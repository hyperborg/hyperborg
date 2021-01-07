#include <hddtemp.h>

hddtemp::hddtemp(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","hddtemp");
	manifest.insert("domain","hddtemp");
}

hddtemp::~hddtemp()
{
}

void hddtemp::init()
{
}


