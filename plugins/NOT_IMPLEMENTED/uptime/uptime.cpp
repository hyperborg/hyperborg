#include <uptime.h>

uptime::uptime(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Uptime");
	manifest.insert("domain","uptime");
}

uptime::~uptime()
{
}

void uptime::init()
{
}


