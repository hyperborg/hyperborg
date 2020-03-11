#include <scrape.h>

scrape::scrape(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Scrape");
	manifest.insert("domain","scrape");
}

scrape::~scrape()
{
}

void scrape::init()
{
}


