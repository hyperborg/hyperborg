#include <reddit.h>

reddit::reddit(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Reddit");
	manifest.insert("domain","reddit");
}

reddit::~reddit()
{
}

void reddit::init()
{
}


