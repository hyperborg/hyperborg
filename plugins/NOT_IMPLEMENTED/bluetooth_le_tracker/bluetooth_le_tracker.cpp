#include <bluetooth_le_tracker.h>

bluetooth_le_tracker::bluetooth_le_tracker(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bluetooth LE Tracker");
	manifest.insert("domain","bluetooth_le_tracker");
}

bluetooth_le_tracker::~bluetooth_le_tracker()
{
}

void bluetooth_le_tracker::init()
{
}


