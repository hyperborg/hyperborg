#include <broadlink.h>

broadlink::broadlink(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Broadlink");
	manifest.insert("domain","broadlink");
}

broadlink::~broadlink()
{
}

void broadlink::init()
{
}

void broadlink::data_packet()
{
}


void broadlink::hostname()
{
}


void broadlink::mac_address()
{
}


void broadlink::async_setup_service()
{
}


void broadlink::_learn_command()
{
}


void broadlink::_send_packet()
{
}


