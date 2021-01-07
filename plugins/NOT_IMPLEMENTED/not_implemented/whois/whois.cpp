#include <whois.h>

whois::whois(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Whois");
	manifest.insert("domain","whois");
}

whois::~whois()
{
}

void whois::init()
{
}


