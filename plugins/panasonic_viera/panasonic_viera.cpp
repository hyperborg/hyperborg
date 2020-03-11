#include <panasonic_viera.h>

panasonic_viera::panasonic_viera(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Panasonic Viera TV");
	manifest.insert("domain","panasonic_viera");
}

panasonic_viera::~panasonic_viera()
{
}

void panasonic_viera::init()
{
}


