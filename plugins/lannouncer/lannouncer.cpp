#include <lannouncer.h>

lannouncer::lannouncer(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LANnouncer");
	manifest.insert("domain","lannouncer");
}

lannouncer::~lannouncer()
{
}

void lannouncer::init()
{
}


