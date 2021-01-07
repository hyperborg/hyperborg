#include <efergy.h>

efergy::efergy(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Efergy");
	manifest.insert("domain","efergy");
}

efergy::~efergy()
{
}

void efergy::init()
{
}


