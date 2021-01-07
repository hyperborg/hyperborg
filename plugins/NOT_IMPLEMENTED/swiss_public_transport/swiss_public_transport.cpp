#include <swiss_public_transport.h>

swiss_public_transport::swiss_public_transport(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Swiss public transport");
	manifest.insert("domain","swiss_public_transport");
}

swiss_public_transport::~swiss_public_transport()
{
}

void swiss_public_transport::init()
{
}


