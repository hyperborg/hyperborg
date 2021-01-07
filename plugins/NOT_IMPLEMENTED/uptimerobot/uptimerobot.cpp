#include <uptimerobot.h>

uptimerobot::uptimerobot(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Uptime Robot");
	manifest.insert("domain","uptimerobot");
}

uptimerobot::~uptimerobot()
{
}

void uptimerobot::init()
{
}


