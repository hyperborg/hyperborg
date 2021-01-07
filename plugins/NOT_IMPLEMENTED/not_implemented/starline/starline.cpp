#include <starline.h>

starline::starline(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","StarLine");
	manifest.insert("domain","starline");
}

starline::~starline()
{
}

void starline::init()
{
}

void starline::async_setup()
{
}


void starline::async_setup_entry()
{
}


void starline::async_set_scan_interval()
{
}


void starline::async_unload_entry()
{
}


void starline::async_options_updated()
{
}


