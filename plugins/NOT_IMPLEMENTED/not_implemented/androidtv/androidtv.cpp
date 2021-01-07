#include <androidtv.h>

androidtv::androidtv(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Android TV");
	manifest.insert("domain","androidtv");
}

androidtv::~androidtv()
{
}

void androidtv::init()
{
}


