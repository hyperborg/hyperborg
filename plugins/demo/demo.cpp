#include <demo.h>

demo::demo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Demo");
	manifest.insert("domain","demo");
}

demo::~demo()
{
}

void demo::init()
{
}

void demo::async_setup()
{
}


void demo::hue_configuration_callback()
{
}


void demo::demo_start_listener()
{
}


void demo::async_setup_entry()
{
}


void demo::finish_setup()
{
}


