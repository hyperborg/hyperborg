#include <pioneer.h>

pioneer::pioneer(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Pioneer");
	manifest.insert("domain","pioneer");
}

pioneer::~pioneer()
{
}

void pioneer::init()
{
}


