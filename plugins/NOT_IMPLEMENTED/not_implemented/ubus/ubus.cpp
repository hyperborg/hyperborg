#include <ubus.h>

ubus::ubus(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OpenWrt (ubus)");
	manifest.insert("domain","ubus");
}

ubus::~ubus()
{
}

void ubus::init()
{
}


