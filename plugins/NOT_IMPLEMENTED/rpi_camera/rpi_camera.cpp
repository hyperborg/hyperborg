#include <rpi_camera.h>

rpi_camera::rpi_camera(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Raspberry Pi Camera");
	manifest.insert("domain","rpi_camera");
}

rpi_camera::~rpi_camera()
{
}

void rpi_camera::init()
{
}


