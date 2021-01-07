#include <entur_public_transport.h>

entur_public_transport::entur_public_transport(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Entur");
	manifest.insert("domain","entur_public_transport");
}

entur_public_transport::~entur_public_transport()
{
}

void entur_public_transport::init()
{
}


