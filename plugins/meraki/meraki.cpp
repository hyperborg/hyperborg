#include <meraki.h>

meraki::meraki(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Meraki");
	manifest.insert("domain","meraki");
}

meraki::~meraki()
{
}

void meraki::init()
{
}


