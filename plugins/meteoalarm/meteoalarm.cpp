#include <meteoalarm.h>

meteoalarm::meteoalarm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MeteoAlarm");
	manifest.insert("domain","meteoalarm");
}

meteoalarm::~meteoalarm()
{
}

void meteoalarm::init()
{
}


