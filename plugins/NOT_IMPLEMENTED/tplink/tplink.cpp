#include <tplink.h>

tplink::tplink(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","TP-Link Kasa Smart");
	manifest.insert("domain","tplink");
}

tplink::~tplink()
{
}

void tplink::init()
{
}

void tplink::async_setup()
{
}


void tplink::async_setup_entry()
{
}


void tplink::async_unload_entry()
{
}


