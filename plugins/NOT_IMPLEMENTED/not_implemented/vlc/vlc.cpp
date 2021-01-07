#include <vlc.h>

vlc::vlc(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","VLC media player");
	manifest.insert("domain","vlc");
}

vlc::~vlc()
{
}

void vlc::init()
{
}


