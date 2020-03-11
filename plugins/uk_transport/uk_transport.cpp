#include <uk_transport.h>

uk_transport::uk_transport(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","UK Transport");
	manifest.insert("domain","uk_transport");
}

uk_transport::~uk_transport()
{
}

void uk_transport::init()
{
}


