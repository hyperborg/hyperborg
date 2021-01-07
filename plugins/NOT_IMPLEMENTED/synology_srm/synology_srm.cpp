#include <synology_srm.h>

synology_srm::synology_srm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Synology SRM");
	manifest.insert("domain","synology_srm");
}

synology_srm::~synology_srm()
{
}

void synology_srm::init()
{
}


