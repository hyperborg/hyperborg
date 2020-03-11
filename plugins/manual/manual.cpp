#include <manual.h>

manual::manual(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Manual");
	manifest.insert("domain","manual");
}

manual::~manual()
{
}

void manual::init()
{
}


