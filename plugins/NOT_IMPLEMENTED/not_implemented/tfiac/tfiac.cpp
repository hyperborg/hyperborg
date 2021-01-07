#include <tfiac.h>

tfiac::tfiac(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Tfiac");
	manifest.insert("domain","tfiac");
}

tfiac::~tfiac()
{
}

void tfiac::init()
{
}


