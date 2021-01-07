#include <free_mobile.h>

free_mobile::free_mobile(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Free Mobile");
	manifest.insert("domain","free_mobile");
}

free_mobile::~free_mobile()
{
}

void free_mobile::init()
{
}


