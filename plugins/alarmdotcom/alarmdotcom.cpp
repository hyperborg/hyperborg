#include <alarmdotcom.h>

alarmdotcom::alarmdotcom(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Alarm.com");
	manifest.insert("domain","alarmdotcom");
}

alarmdotcom::~alarmdotcom()
{
}

void alarmdotcom::init()
{
}


