#include <switchbot.h>

switchbot::switchbot(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SwitchBot");
	manifest.insert("domain","switchbot");
}

switchbot::~switchbot()
{
}

void switchbot::init()
{
}


