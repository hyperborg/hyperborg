#include <notify.h>

notify::notify(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Notifications");
	manifest.insert("domain","notify");
}

notify::~notify()
{
}

void notify::init()
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


