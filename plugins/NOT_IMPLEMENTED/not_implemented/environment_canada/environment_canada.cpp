#include <environment_canada.h>

environment_canada::environment_canada(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Environment Canada");
	manifest.insert("domain","environment_canada");
}

environment_canada::~environment_canada()
{
}

void environment_canada::init()
{
}


