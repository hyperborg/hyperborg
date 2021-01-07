#include <rocketchat.h>

rocketchat::rocketchat(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Rocket.Chat");
	manifest.insert("domain","rocketchat");
}

rocketchat::~rocketchat()
{
}

void rocketchat::init()
{
}


