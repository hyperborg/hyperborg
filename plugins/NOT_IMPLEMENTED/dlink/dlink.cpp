#include <dlink.h>

dlink::dlink(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","D-Link Wi-Fi Smart Plugs");
	manifest.insert("domain","dlink");
}

dlink::~dlink()
{
}

void dlink::init()
{
}


