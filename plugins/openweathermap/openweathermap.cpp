#include <openweathermap.h>

openweathermap::openweathermap(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Openweathermap");
	manifest.insert("domain","openweathermap");
}

openweathermap::~openweathermap()
{
}

void openweathermap::init()
{
}


