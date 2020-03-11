#include <yr.h>

yr::yr(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Yr");
	manifest.insert("domain","yr");
}

yr::~yr()
{
}

void yr::init()
{
}


