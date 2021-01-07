#include <orvibo.h>

orvibo::orvibo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Orvibo");
	manifest.insert("domain","orvibo");
}

orvibo::~orvibo()
{
}

void orvibo::init()
{
}


