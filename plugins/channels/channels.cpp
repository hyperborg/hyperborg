#include <channels.h>

channels::channels(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Channels");
	manifest.insert("domain","channels");
}

channels::~channels()
{
}

void channels::init()
{
}


