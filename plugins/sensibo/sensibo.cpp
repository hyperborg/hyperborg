#include <sensibo.h>

sensibo::sensibo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sensibo");
	manifest.insert("domain","sensibo");
}

sensibo::~sensibo()
{
}

void sensibo::init()
{
}


