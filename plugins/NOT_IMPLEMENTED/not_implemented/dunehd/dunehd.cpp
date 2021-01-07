#include <dunehd.h>

dunehd::dunehd(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DuneHD");
	manifest.insert("domain","dunehd");
}

dunehd::~dunehd()
{
}

void dunehd::init()
{
}


