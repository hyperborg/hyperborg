#include <enphase_envoy.h>

enphase_envoy::enphase_envoy(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Enphase Envoy");
	manifest.insert("domain","enphase_envoy");
}

enphase_envoy::~enphase_envoy()
{
}

void enphase_envoy::init()
{
}


