#include <freedns.h>

freedns::freedns(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","FreeDNS");
	manifest.insert("domain","freedns");
}

freedns::~freedns()
{
}

void freedns::init()
{
}

void freedns::async_setup()
{
}


void freedns::update_domain_callback()
{
}


void freedns::_update_freedns()
{
}


