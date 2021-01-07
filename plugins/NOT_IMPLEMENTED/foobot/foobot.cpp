#include <foobot.h>

foobot::foobot(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Foobot");
	manifest.insert("domain","foobot");
}

foobot::~foobot()
{
}

void foobot::init()
{
}


