#include <dnsip.h>

dnsip::dnsip(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DNS IP");
	manifest.insert("domain","dnsip");
}

dnsip::~dnsip()
{
}

void dnsip::init()
{
}


