#include <gtfs.h>

gtfs::gtfs(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","General Transit Feed Specification (GTFS)");
	manifest.insert("domain","gtfs");
}

gtfs::~gtfs()
{
}

void gtfs::init()
{
}


