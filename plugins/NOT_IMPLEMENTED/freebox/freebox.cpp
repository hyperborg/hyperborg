#include <freebox.h>

freebox::freebox(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Freebox");
	manifest.insert("domain","freebox");
}

freebox::~freebox()
{
}

void freebox::init()
{
}

void freebox::async_setup()
{
}


void freebox::discovery_dispatch()
{
}


void freebox::async_setup_freebox()
{
}


void freebox::async_freebox_reboot()
{
}


void freebox::close_fbx()
{
}


