#include <geizhals.h>

geizhals::geizhals(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Geizhals");
	manifest.insert("domain","geizhals");
}

geizhals::~geizhals()
{
}

void geizhals::init()
{
}


