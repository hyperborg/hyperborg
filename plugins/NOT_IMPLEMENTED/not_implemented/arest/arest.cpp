#include <arest.h>

arest::arest(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","aREST");
	manifest.insert("domain","arest");
}

arest::~arest()
{
}

void arest::init()
{
}


