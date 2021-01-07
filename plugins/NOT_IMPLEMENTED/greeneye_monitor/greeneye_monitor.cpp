#include <greeneye_monitor.h>

greeneye_monitor::greeneye_monitor(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","GreenEye Monitor (GEM)");
	manifest.insert("domain","greeneye_monitor");
}

greeneye_monitor::~greeneye_monitor()
{
}

void greeneye_monitor::init()
{
}

void greeneye_monitor::async_setup()
{
}


void greeneye_monitor::close_server()
{
}


