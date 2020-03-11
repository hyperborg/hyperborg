#include <nfandroidtv.h>

nfandroidtv::nfandroidtv(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Notifications for Android TV / FireTV");
	manifest.insert("domain","nfandroidtv");
}

nfandroidtv::~nfandroidtv()
{
}

void nfandroidtv::init()
{
}


