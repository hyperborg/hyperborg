#include <sigfox.h>

sigfox::sigfox(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sigfox");
	manifest.insert("domain","sigfox");
}

sigfox::~sigfox()
{
}

void sigfox::init()
{
}


