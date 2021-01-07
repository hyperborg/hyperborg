#include <itach.h>

itach::itach(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Global Caché iTach TCP/IP to IR");
	manifest.insert("domain","itach");
}

itach::~itach()
{
}

void itach::init()
{
}


