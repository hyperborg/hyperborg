#include <nilu.h>

nilu::nilu(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Norwegian Institute for Air Research (NILU)");
	manifest.insert("domain","nilu");
}

nilu::~nilu()
{
}

void nilu::init()
{
}


