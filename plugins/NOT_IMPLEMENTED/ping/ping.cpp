#include <ping.h>

ping::ping(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ping (ICMP)");
	manifest.insert("domain","ping");
}

ping::~ping()
{
}

void ping::init()
{
}


