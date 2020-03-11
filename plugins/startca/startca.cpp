#include <startca.h>

startca::startca(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Start.ca");
	manifest.insert("domain","startca");
}

startca::~startca()
{
}

void startca::init()
{
}


