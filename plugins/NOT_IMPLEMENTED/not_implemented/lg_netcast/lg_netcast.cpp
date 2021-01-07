#include <lg_netcast.h>

lg_netcast::lg_netcast(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LG Netcast");
	manifest.insert("domain","lg_netcast");
}

lg_netcast::~lg_netcast()
{
}

void lg_netcast::init()
{
}


