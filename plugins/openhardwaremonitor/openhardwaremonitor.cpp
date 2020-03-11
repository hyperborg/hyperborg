#include <openhardwaremonitor.h>

openhardwaremonitor::openhardwaremonitor(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Open Hardware Monitor");
	manifest.insert("domain","openhardwaremonitor");
}

openhardwaremonitor::~openhardwaremonitor()
{
}

void openhardwaremonitor::init()
{
}


