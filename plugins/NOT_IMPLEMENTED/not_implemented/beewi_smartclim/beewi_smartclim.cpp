#include <beewi_smartclim.h>

beewi_smartclim::beewi_smartclim(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","BeeWi SmartClim BLE sensor");
	manifest.insert("domain","beewi_smartclim");
}

beewi_smartclim::~beewi_smartclim()
{
}

void beewi_smartclim::init()
{
}


