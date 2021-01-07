#include <tmb.h>

tmb::tmb(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Transports Metropolitans de Barcelona");
	manifest.insert("domain","tmb");
}

tmb::~tmb()
{
}

void tmb::init()
{
}


