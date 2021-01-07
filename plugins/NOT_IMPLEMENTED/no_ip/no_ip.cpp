#include <no_ip.h>

no_ip::no_ip(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","No-IP.com");
	manifest.insert("domain","no_ip");
}

no_ip::~no_ip()
{
}

void no_ip::init()
{
}

void no_ip::async_setup()
{
}


void no_ip::update_domain_interval()
{
}


void no_ip::_update_no_ip()
{
}


