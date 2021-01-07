#include <bme280.h>

bme280::bme280(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bosch BME280 Environmental Sensor");
	manifest.insert("domain","bme280");
}

bme280::~bme280()
{
}

void bme280::init()
{
}


