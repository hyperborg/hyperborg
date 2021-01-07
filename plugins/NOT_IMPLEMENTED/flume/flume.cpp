#include <flume.h>

flume::flume(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","flume");
	manifest.insert("domain","flume");
}

flume::~flume()
{
}

void flume::init()
{
}


