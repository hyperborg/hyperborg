#include <dwd_weather_warnings.h>

dwd_weather_warnings::dwd_weather_warnings(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Deutsche Wetter Dienst (DWD) Weather Warnings");
	manifest.insert("domain","dwd_weather_warnings");
}

dwd_weather_warnings::~dwd_weather_warnings()
{
}

void dwd_weather_warnings::init()
{
}


