#include <rpi_rf.h>

rpi_rf::rpi_rf(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Raspberry Pi RF");
	manifest.insert("domain","rpi_rf");
}

rpi_rf::~rpi_rf()
{
}

void rpi_rf::init()
{
}


