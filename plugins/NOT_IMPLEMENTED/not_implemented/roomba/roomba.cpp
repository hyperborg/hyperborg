#include <roomba.h>

roomba::roomba(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","iRobot Roomba");
	manifest.insert("domain","roomba");
}

roomba::~roomba()
{
}

void roomba::init()
{
}


