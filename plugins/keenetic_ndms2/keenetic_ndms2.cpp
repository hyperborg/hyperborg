#include <keenetic_ndms2.h>

keenetic_ndms2::keenetic_ndms2(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Keenetic NDMS2 Routers");
	manifest.insert("domain","keenetic_ndms2");
}

keenetic_ndms2::~keenetic_ndms2()
{
}

void keenetic_ndms2::init()
{
}


