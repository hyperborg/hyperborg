#include <tcp.h>

tcp::tcp(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","TCP");
	manifest.insert("domain","tcp");
}

tcp::~tcp()
{
}

void tcp::init()
{
}


