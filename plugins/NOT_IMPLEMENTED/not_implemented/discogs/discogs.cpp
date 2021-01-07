#include <discogs.h>

discogs::discogs(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Discogs");
	manifest.insert("domain","discogs");
}

discogs::~discogs()
{
}

void discogs::init()
{
}


