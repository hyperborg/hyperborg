#include <ign_sismologia.h>

ign_sismologia::ign_sismologia(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","IGN Sismología");
	manifest.insert("domain","ign_sismologia");
}

ign_sismologia::~ign_sismologia()
{
}

void ign_sismologia::init()
{
}


