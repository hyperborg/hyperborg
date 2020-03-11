#include <apns.h>

apns::apns(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Apple Push Notification Service (APNS)");
	manifest.insert("domain","apns");
}

apns::~apns()
{
}

void apns::init()
{
}


