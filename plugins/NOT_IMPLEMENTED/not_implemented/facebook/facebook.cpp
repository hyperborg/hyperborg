#include <facebook.h>

facebook::facebook(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Facebook Messenger");
	manifest.insert("domain","facebook");
}

facebook::~facebook()
{
}

void facebook::init()
{
}


