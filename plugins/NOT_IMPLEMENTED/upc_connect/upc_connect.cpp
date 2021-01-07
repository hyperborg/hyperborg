#include <upc_connect.h>

upc_connect::upc_connect(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","UPC Connect Box");
	manifest.insert("domain","upc_connect");
}

upc_connect::~upc_connect()
{
}

void upc_connect::init()
{
}


