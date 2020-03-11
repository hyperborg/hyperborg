#include <bluetooth_tracker.h>

bluetooth_tracker::bluetooth_tracker(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bluetooth Tracker");
	manifest.insert("domain","bluetooth_tracker");
}

bluetooth_tracker::~bluetooth_tracker()
{
}

void bluetooth_tracker::init()
{
}


