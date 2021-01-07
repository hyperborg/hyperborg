#include <netio.h>

netio::netio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Netio");
	manifest.insert("domain","netio");
}

netio::~netio()
{
}

void netio::init()
{
}


