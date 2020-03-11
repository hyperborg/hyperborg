#include <bme680.h>

bme680::bme680(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bosch BME680 Environmental Sensor");
	manifest.insert("domain","bme680");
}

bme680::~bme680()
{
}

void bme680::init()
{
}


