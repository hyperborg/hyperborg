#include <vizio.h>

vizio::vizio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Vizio SmartCast");
	manifest.insert("domain","vizio");
}

vizio::~vizio()
{
}

void vizio::init()
{
}

void vizio::async_setup()
{
}


void vizio::async_setup_entry()
{
}


void vizio::async_unload_entry()
{
}


