#include <coolmaster.h>

coolmaster::coolmaster(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","CoolMasterNet");
	manifest.insert("domain","coolmaster");
}

coolmaster::~coolmaster()
{
}

void coolmaster::init()
{
}

void coolmaster::async_setup()
{
}


void coolmaster::async_setup_entry()
{
}


void coolmaster::async_unload_entry()
{
}


