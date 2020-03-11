#include <html5.h>

html5::html5(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","HTML5 Push Notifications");
	manifest.insert("domain","html5");
}

html5::~html5()
{
}

void html5::init()
{
}


