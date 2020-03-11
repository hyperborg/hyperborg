#include <panasonic_bluray.h>

panasonic_bluray::panasonic_bluray(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Panasonic Blu-Ray Player");
	manifest.insert("domain","panasonic_bluray");
}

panasonic_bluray::~panasonic_bluray()
{
}

void panasonic_bluray::init()
{
}


