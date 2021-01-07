#include <ifttt.h>

ifttt::ifttt(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","IFTTT");
	manifest.insert("domain","ifttt");
}

ifttt::~ifttt()
{
}

void ifttt::init()
{
}

void ifttt::async_setup()
{
}


void ifttt::trigger_service()
{
}


void ifttt::handle_webhook()
{
}


void ifttt::async_setup_entry()
{
}


void ifttt::async_unload_entry()
{
}


