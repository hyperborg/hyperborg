#include <panel_iframe.h>

panel_iframe::panel_iframe(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","iframe Panel");
	manifest.insert("domain","panel_iframe");
}

panel_iframe::~panel_iframe()
{
}

void panel_iframe::init()
{
}

void panel_iframe::async_setup()
{
}


