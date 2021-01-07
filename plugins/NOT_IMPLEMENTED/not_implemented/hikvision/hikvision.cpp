#include <hikvision.h>

hikvision::hikvision(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Hikvision");
	manifest.insert("domain","hikvision");
}

hikvision::~hikvision()
{
}

void hikvision::init()
{
}


