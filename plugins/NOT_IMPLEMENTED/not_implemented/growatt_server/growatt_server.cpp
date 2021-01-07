#include <growatt_server.h>

growatt_server::growatt_server(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Growatt");
	manifest.insert("domain","growatt_server");
}

growatt_server::~growatt_server()
{
}

void growatt_server::init()
{
}


