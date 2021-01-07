#include <econet.h>

econet::econet(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Rheem EcoNET Water Products");
	manifest.insert("domain","econet");
}

econet::~econet()
{
}

void econet::init()
{
}


