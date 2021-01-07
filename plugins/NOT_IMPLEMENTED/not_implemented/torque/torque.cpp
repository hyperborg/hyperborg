#include <torque.h>

torque::torque(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Torque");
	manifest.insert("domain","torque");
}

torque::~torque()
{
}

void torque::init()
{
}


