#include <panel_custom.h>

panel_custom::panel_custom(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Custom Panel");
	manifest.insert("domain","panel_custom");
}

panel_custom::~panel_custom()
{
}

void panel_custom::init()
{
}

void panel_custom::async_register_panel()
{
}


void panel_custom::async_setup()
{
}


