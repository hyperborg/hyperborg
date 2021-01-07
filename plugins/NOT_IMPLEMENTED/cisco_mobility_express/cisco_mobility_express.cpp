#include <cisco_mobility_express.h>

cisco_mobility_express::cisco_mobility_express(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Cisco Mobility Express");
	manifest.insert("domain","cisco_mobility_express");
}

cisco_mobility_express::~cisco_mobility_express()
{
}

void cisco_mobility_express::init()
{
}


