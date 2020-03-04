#include <notify.h>

notify::notify()
{
    	manifest.insert("name","Notifications");
	manifest.insert("domain","notify");
}

notify::~notify()
{
}

void notify::async_setup()
{
}


void notify::async_setup_platform()
{
}


void notify::async_notify_message()
{
}


void notify::async_platform_discovered()
{
}


void notify::send_message()
{
}


void notify::async_send_message()
{
}


