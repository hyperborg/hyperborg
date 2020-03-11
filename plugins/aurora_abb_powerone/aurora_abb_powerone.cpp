#include <aurora_abb_powerone.h>

aurora_abb_powerone::aurora_abb_powerone(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Aurora ABB Solar PV");
	manifest.insert("domain","aurora_abb_powerone");
}

aurora_abb_powerone::~aurora_abb_powerone()
{
}

void aurora_abb_powerone::init()
{
}


