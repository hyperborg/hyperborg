#include <qbittorrent.h>

qbittorrent::qbittorrent(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","qBittorrent");
	manifest.insert("domain","qbittorrent");
}

qbittorrent::~qbittorrent()
{
}

void qbittorrent::init()
{
}


