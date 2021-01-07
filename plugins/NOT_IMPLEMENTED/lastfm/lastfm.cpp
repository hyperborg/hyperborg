#include <lastfm.h>

lastfm::lastfm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Last.fm");
	manifest.insert("domain","lastfm");
}

lastfm::~lastfm()
{
}

void lastfm::init()
{
}


