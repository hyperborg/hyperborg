#include <icloud.h>

icloud::icloud(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Apple iCloud");
	manifest.insert("domain","icloud");
}

icloud::~icloud()
{
}

void icloud::init()
{
}

void icloud::async_setup()
{
}


void icloud::async_setup_entry()
{
}


void icloud::play_sound()
{
}


void icloud::display_message()
{
}


void icloud::lost_device()
{
}


void icloud::update_account()
{
}


void icloud::_get_account()
{
}


void icloud::async_unload_entry()
{
}


