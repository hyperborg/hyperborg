#include <shodan.h>

shodan::shodan(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Shodan");
	manifest.insert("domain","shodan");
}

shodan::~shodan()
{
}

void shodan::init()
{
}


