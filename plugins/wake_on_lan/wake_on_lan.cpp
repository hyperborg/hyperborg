#include <wake_on_lan.h>

wake_on_lan::wake_on_lan()
{
    	manifest.insert("domain","wake_on_lan");
	manifest.insert("name","Wake on LAN");
}

wake_on_lan::~wake_on_lan()
{
}

void wake_on_lan:: async_setup()
{
}


void wake_on_lan:: send_magic_packet()
{
}


