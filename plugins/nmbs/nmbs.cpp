#include <nmbs.h>

nmbs::nmbs(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","NMBS");
	manifest.insert("domain","nmbs");
}

nmbs::~nmbs()
{
}

void nmbs::init()
{
}


