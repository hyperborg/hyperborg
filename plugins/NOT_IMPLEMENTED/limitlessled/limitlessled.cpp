#include <limitlessled.h>

limitlessled::limitlessled(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LimitlessLED");
	manifest.insert("domain","limitlessled");
}

limitlessled::~limitlessled()
{
}

void limitlessled::init()
{
}


