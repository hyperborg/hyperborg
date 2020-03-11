#include <fritzbox_netmonitor.h>

fritzbox_netmonitor::fritzbox_netmonitor(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","AVM FRITZ!Box Net Monitor");
	manifest.insert("domain","fritzbox_netmonitor");
}

fritzbox_netmonitor::~fritzbox_netmonitor()
{
}

void fritzbox_netmonitor::init()
{
}


