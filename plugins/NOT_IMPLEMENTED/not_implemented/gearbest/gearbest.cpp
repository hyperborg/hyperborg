#include <gearbest.h>

gearbest::gearbest(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Gearbest");
	manifest.insert("domain","gearbest");
}

gearbest::~gearbest()
{
}

void gearbest::init()
{
}


