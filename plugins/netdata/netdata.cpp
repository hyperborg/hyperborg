#include <netdata.h>

netdata::netdata(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Netdata");
	manifest.insert("domain","netdata");
}

netdata::~netdata()
{
}

void netdata::init()
{
}


