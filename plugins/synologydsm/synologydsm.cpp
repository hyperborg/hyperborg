#include <synologydsm.h>

synologydsm::synologydsm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SynologyDSM");
	manifest.insert("domain","synologydsm");
}

synologydsm::~synologydsm()
{
}

void synologydsm::init()
{
}


