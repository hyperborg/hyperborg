#include <sonarr.h>

sonarr::sonarr(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sonarr");
	manifest.insert("domain","sonarr");
}

sonarr::~sonarr()
{
}

void sonarr::init()
{
}


