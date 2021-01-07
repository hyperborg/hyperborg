#include <linux_battery.h>

linux_battery::linux_battery(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Linux Battery");
	manifest.insert("domain","linux_battery");
}

linux_battery::~linux_battery()
{
}

void linux_battery::init()
{
}


