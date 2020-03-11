#include <telnet.h>

telnet::telnet(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Telnet");
	manifest.insert("domain","telnet");
}

telnet::~telnet()
{
}

void telnet::init()
{
}


