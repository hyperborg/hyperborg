#include <transport_nsw.h>

transport_nsw::transport_nsw(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Transport NSW");
	manifest.insert("domain","transport_nsw");
}

transport_nsw::~transport_nsw()
{
}

void transport_nsw::init()
{
}


