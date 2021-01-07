#include <irish_rail_transport.h>

irish_rail_transport::irish_rail_transport(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Irish Rail Transport");
	manifest.insert("domain","irish_rail_transport");
}

irish_rail_transport::~irish_rail_transport()
{
}

void irish_rail_transport::init()
{
}


