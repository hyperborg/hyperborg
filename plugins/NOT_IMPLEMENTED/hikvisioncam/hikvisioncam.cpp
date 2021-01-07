#include <hikvisioncam.h>

hikvisioncam::hikvisioncam(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Hikvision");
	manifest.insert("domain","hikvisioncam");
}

hikvisioncam::~hikvisioncam()
{
}

void hikvisioncam::init()
{
}


