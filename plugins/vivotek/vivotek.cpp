#include <vivotek.h>

vivotek::vivotek(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","VIVOTEK");
	manifest.insert("domain","vivotek");
}

vivotek::~vivotek()
{
}

void vivotek::init()
{
}


