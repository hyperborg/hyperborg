#include <aftership.h>

aftership::aftership(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","AfterShip");
	manifest.insert("domain","aftership");
}

aftership::~aftership()
{
}

void aftership::init()
{
}


