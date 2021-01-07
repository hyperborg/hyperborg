#include <spaceapi.h>

spaceapi::spaceapi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Space API");
	manifest.insert("domain","spaceapi");
}

spaceapi::~spaceapi()
{
}

void spaceapi::init()
{
}

void spaceapi::setup()
{
}


void spaceapi::get_sensor_data()
{
}


