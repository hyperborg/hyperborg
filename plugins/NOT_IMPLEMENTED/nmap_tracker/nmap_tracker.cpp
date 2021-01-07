#include <nmap_tracker.h>

nmap_tracker::nmap_tracker(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Nmap Tracker");
	manifest.insert("domain","nmap_tracker");
}

nmap_tracker::~nmap_tracker()
{
}

void nmap_tracker::init()
{
}


