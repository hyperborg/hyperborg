#include <nad.h>

nad::nad(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","NAD");
	manifest.insert("domain","nad");
}

nad::~nad()
{
}

void nad::init()
{
}


