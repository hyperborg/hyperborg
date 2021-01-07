#include <apprise.h>

apprise::apprise(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Apprise");
	manifest.insert("domain","apprise");
}

apprise::~apprise()
{
}

void apprise::init()
{
}


