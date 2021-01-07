#include <mpd.h>

mpd::mpd(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Music Player Daemon (MPD)");
	manifest.insert("domain","mpd");
}

mpd::~mpd()
{
}

void mpd::init()
{
}


