#include <yamaha.h>

yamaha::yamaha(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Yamaha Network Receivers");
	manifest.insert("domain","yamaha");
}

yamaha::~yamaha()
{
}

void yamaha::init()
{
}


