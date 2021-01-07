#include <namecheapdns.h>

namecheapdns::namecheapdns(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Namecheap FreeDNS");
	manifest.insert("domain","namecheapdns");
}

namecheapdns::~namecheapdns()
{
}

void namecheapdns::init()
{
}

void namecheapdns::async_setup()
{
}


void namecheapdns::update_domain_interval()
{
}


void namecheapdns::_update_namecheapdns()
{
}


