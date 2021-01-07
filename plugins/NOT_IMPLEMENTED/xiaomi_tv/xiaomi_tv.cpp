#include <xiaomi_tv.h>

xiaomi_tv::xiaomi_tv(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Xiaomi TV");
	manifest.insert("domain","xiaomi_tv");
}

xiaomi_tv::~xiaomi_tv()
{
}

void xiaomi_tv::init()
{
}


