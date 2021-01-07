#include <ripple.h>

ripple::ripple(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ripple");
	manifest.insert("domain","ripple");
}

ripple::~ripple()
{
}

void ripple::init()
{
}


