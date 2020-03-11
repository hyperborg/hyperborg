#include <mailgun.h>

mailgun::mailgun(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Mailgun");
	manifest.insert("domain","mailgun");
}

mailgun::~mailgun()
{
}

void mailgun::init()
{
}

void mailgun::async_setup()
{
}


void mailgun::handle_webhook()
{
}


void mailgun::verify_webhook()
{
}


void mailgun::async_setup_entry()
{
}


void mailgun::async_unload_entry()
{
}


