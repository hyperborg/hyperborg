#include <persistent_notification.h>

persistent_notification::persistent_notification(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Persistent Notification");
	manifest.insert("domain","persistent_notification");
}

persistent_notification::~persistent_notification()
{
}

void persistent_notification::init()
{
}

void persistent_notification::create()
{
}


void persistent_notification::dismiss()
{
}


void persistent_notification::async_create()
{
}


void persistent_notification::async_dismiss()
{
}


void persistent_notification::async_setup()
{
}


void persistent_notification::create_service()
{
}


void persistent_notification::dismiss_service()
{
}


void persistent_notification::mark_read_service()
{
}


void persistent_notification::websocket_get_notifications()
{
}


