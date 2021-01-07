#include <bluesound.h>

bluesound::bluesound(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bluesound");
	manifest.insert("domain","bluesound");
}

bluesound::~bluesound()
{
}

void bluesound::init()
{
}


