#include <denon.h>

denon::denon(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Denon Network Receivers");
	manifest.insert("domain","denon");
}

denon::~denon()
{
}

void denon::init()
{
}


