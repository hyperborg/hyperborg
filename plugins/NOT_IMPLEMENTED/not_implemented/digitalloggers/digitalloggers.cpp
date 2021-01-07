#include <digitalloggers.h>

digitalloggers::digitalloggers(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Digital Loggers");
	manifest.insert("domain","digitalloggers");
}

digitalloggers::~digitalloggers()
{
}

void digitalloggers::init()
{
}


