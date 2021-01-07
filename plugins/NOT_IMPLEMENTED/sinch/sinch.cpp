#include <sinch.h>

sinch::sinch(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sinch SMS");
	manifest.insert("domain","sinch");
}

sinch::~sinch()
{
}

void sinch::init()
{
}


