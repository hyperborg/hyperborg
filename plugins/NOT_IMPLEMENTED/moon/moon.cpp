#include <moon.h>

moon::moon(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Moon");
	manifest.insert("domain","moon");
}

moon::~moon()
{
}

void moon::init()
{
}


