#include <wsdot.h>

wsdot::wsdot(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Washington State Department of Transportation (WSDOT)");
	manifest.insert("domain","wsdot");
}

wsdot::~wsdot()
{
}

void wsdot::init()
{
}


