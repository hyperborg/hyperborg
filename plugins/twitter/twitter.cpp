#include <twitter.h>

twitter::twitter(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Twitter");
	manifest.insert("domain","twitter");
}

twitter::~twitter()
{
}

void twitter::init()
{
}


