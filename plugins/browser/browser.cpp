#include <browser.h>

browser::browser(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Browser");
	manifest.insert("domain","browser");
}

browser::~browser()
{
}

void browser::init()
{
}

void browser::setup()
{
}


