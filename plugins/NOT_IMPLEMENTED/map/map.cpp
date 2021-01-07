#include <map.h>

map::map(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Map");
	manifest.insert("domain","map");
}

map::~map()
{
}

void map::init()
{
}

void map::async_setup()
{
}


