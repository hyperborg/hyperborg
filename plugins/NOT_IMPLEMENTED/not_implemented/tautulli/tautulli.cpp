#include <tautulli.h>

tautulli::tautulli(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Tautulli");
	manifest.insert("domain","tautulli");
}

tautulli::~tautulli()
{
}

void tautulli::init()
{
}


