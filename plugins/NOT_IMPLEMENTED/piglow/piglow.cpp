#include <piglow.h>

piglow::piglow(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Piglow");
	manifest.insert("domain","piglow");
}

piglow::~piglow()
{
}

void piglow::init()
{
}


