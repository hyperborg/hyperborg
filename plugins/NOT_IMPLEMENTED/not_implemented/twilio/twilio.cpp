#include <twilio.h>

twilio::twilio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Twilio");
	manifest.insert("domain","twilio");
}

twilio::~twilio()
{
}

void twilio::init()
{
}

void twilio::async_setup()
{
}


void twilio::handle_webhook()
{
}


void twilio::async_setup_entry()
{
}


void twilio::async_unload_entry()
{
}


