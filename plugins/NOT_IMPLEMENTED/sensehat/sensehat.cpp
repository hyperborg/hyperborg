#include <sensehat.h>

sensehat::sensehat(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sense HAT");
	manifest.insert("domain","sensehat");
}

sensehat::~sensehat()
{
}

void sensehat::init()
{
}


