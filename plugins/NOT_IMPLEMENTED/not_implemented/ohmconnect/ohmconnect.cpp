#include <ohmconnect.h>

ohmconnect::ohmconnect(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OhmConnect");
	manifest.insert("domain","ohmconnect");
}

ohmconnect::~ohmconnect()
{
}

void ohmconnect::init()
{
}


