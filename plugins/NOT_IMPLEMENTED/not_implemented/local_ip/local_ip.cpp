#include <local_ip.h>

local_ip::local_ip(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Local IP Address");
	manifest.insert("domain","local_ip");
}

local_ip::~local_ip()
{
}

void local_ip::init()
{
}

void local_ip::async_setup()
{
}


void local_ip::async_setup_entry()
{
}


void local_ip::async_unload_entry()
{
}


