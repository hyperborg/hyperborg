#include <netgear.h>

netgear::netgear(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","NETGEAR");
	manifest.insert("domain","netgear");
}

netgear::~netgear()
{
}

void netgear::init()
{
}


