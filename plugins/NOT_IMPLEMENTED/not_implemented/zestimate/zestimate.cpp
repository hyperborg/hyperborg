#include <zestimate.h>

zestimate::zestimate(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Zestimate");
	manifest.insert("domain","zestimate");
}

zestimate::~zestimate()
{
}

void zestimate::init()
{
}


