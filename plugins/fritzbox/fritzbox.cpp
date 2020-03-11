#include <fritzbox.h>

fritzbox::fritzbox(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","AVM FRITZ!Box");
	manifest.insert("domain","fritzbox");
}

fritzbox::~fritzbox()
{
}

void fritzbox::init()
{
}

void fritzbox::setup()
{
}


void fritzbox::logout_fritzboxes()
{
}


