#include <everlights.h>

everlights::everlights(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","EverLights");
	manifest.insert("domain","everlights");
}

everlights::~everlights()
{
}

void everlights::init()
{
}


