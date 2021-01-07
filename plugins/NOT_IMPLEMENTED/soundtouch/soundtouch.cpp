#include <soundtouch.h>

soundtouch::soundtouch(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bose Soundtouch");
	manifest.insert("domain","soundtouch");
}

soundtouch::~soundtouch()
{
}

void soundtouch::init()
{
}


