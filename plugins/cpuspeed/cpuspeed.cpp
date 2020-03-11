#include <cpuspeed.h>

cpuspeed::cpuspeed(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","CPU Speed");
	manifest.insert("domain","cpuspeed");
}

cpuspeed::~cpuspeed()
{
}

void cpuspeed::init()
{
}


