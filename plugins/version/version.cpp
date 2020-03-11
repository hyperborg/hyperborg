#include <version.h>

version::version(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Version");
	manifest.insert("domain","version");
}

version::~version()
{
}

void version::init()
{
}


