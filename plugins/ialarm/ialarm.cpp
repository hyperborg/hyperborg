#include <ialarm.h>

ialarm::ialarm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Antifurto365 iAlarm");
	manifest.insert("domain","ialarm");
}

ialarm::~ialarm()
{
}

void ialarm::init()
{
}


