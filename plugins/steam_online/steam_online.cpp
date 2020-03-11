#include <steam_online.h>

steam_online::steam_online(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Steam");
	manifest.insert("domain","steam_online");
}

steam_online::~steam_online()
{
}

void steam_online::init()
{
}


