#include <radarr.h>

radarr::radarr(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Radarr");
	manifest.insert("domain","radarr");
}

radarr::~radarr()
{
}

void radarr::init()
{
}


