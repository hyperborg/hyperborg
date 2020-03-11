#include <pushbullet.h>

pushbullet::pushbullet(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Pushbullet");
	manifest.insert("domain","pushbullet");
}

pushbullet::~pushbullet()
{
}

void pushbullet::init()
{
}


