#include <openexchangerates.h>

openexchangerates::openexchangerates(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Open Exchange Rates");
	manifest.insert("domain","openexchangerates");
}

openexchangerates::~openexchangerates()
{
}

void openexchangerates::init()
{
}


