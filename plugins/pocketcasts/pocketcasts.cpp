#include <pocketcasts.h>

pocketcasts::pocketcasts(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Pocket Casts");
	manifest.insert("domain","pocketcasts");
}

pocketcasts::~pocketcasts()
{
}

void pocketcasts::init()
{
}


