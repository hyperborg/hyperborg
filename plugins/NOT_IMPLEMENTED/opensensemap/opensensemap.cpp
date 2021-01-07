#include <opensensemap.h>

opensensemap::opensensemap(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","openSenseMap");
	manifest.insert("domain","opensensemap");
}

opensensemap::~opensensemap()
{
}

void opensensemap::init()
{
}


