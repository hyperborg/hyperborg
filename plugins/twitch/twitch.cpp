#include <twitch.h>

twitch::twitch(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Twitch");
	manifest.insert("domain","twitch");
}

twitch::~twitch()
{
}

void twitch::init()
{
}


