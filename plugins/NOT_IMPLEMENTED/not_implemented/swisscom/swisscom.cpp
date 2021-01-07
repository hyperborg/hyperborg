#include <swisscom.h>

swisscom::swisscom(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Swisscom Internet-Box");
	manifest.insert("domain","swisscom");
}

swisscom::~swisscom()
{
}

void swisscom::init()
{
}


