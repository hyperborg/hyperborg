#include <xiaomi_miio.h>

xiaomi_miio::xiaomi_miio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Xiaomi miio");
	manifest.insert("domain","xiaomi_miio");
}

xiaomi_miio::~xiaomi_miio()
{
}

void xiaomi_miio::init()
{
}


