#include <synology.h>

synology::synology(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Synology");
	manifest.insert("domain","synology");
}

synology::~synology()
{
}

void synology::init()
{
}


