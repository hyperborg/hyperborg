#include <rest.h>

rest::rest(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","RESTful");
	manifest.insert("domain","rest");
}

rest::~rest()
{
}

void rest::init()
{
}


