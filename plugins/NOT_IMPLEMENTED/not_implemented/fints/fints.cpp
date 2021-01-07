#include <fints.h>

fints::fints(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","FinTS");
	manifest.insert("domain","fints");
}

fints::~fints()
{
}

void fints::init()
{
}


