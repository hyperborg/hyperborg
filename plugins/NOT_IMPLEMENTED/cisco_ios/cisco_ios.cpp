#include <cisco_ios.h>

cisco_ios::cisco_ios(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Cisco IOS");
	manifest.insert("domain","cisco_ios");
}

cisco_ios::~cisco_ios()
{
}

void cisco_ios::init()
{
}


