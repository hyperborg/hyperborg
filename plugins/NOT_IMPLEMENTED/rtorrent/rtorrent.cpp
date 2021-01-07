#include <rtorrent.h>

rtorrent::rtorrent(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","rTorrent");
	manifest.insert("domain","rtorrent");
}

rtorrent::~rtorrent()
{
}

void rtorrent::init()
{
}


