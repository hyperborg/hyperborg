#include <fritzbox_callmonitor.h>

fritzbox_callmonitor::fritzbox_callmonitor(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","AVM FRITZ!Box Call Monitor");
	manifest.insert("domain","fritzbox_callmonitor");
}

fritzbox_callmonitor::~fritzbox_callmonitor()
{
}

void fritzbox_callmonitor::init()
{
}


