#include <worxlandroid.h>

worxlandroid::worxlandroid(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Worx Landroid");
	manifest.insert("domain","worxlandroid");
}

worxlandroid::~worxlandroid()
{
}

void worxlandroid::init()
{
}


