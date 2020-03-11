#include <metoffice.h>

metoffice::metoffice(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Met Office");
	manifest.insert("domain","metoffice");
}

metoffice::~metoffice()
{
}

void metoffice::init()
{
}


