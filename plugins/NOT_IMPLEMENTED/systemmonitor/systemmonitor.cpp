#include <systemmonitor.h>

systemmonitor::systemmonitor(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","System Monitor");
	manifest.insert("domain","systemmonitor");
}

systemmonitor::~systemmonitor()
{
}

void systemmonitor::init()
{
}


