#include <wake_on_lan.h>

wake_on_lan::wake_on_lan(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Wake on LAN");
	manifest.insert("domain","wake_on_lan");
}

wake_on_lan::~wake_on_lan()
{
}

void wake_on_lan::init()
{
}

void wake_on_lan::async_setup()
{
}


void wake_on_lan::send_magic_packet()
{
}


