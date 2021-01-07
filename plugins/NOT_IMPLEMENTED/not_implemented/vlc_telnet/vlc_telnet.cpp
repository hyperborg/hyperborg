#include <vlc_telnet.h>

vlc_telnet::vlc_telnet(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","VLC media player Telnet");
	manifest.insert("domain","vlc_telnet");
}

vlc_telnet::~vlc_telnet()
{
}

void vlc_telnet::init()
{
}


