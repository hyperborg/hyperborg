#include <iss.h>

iss::iss(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","International Space Station (ISS)");
	manifest.insert("domain","iss");
}

iss::~iss()
{
}

void iss::init()
{
}


