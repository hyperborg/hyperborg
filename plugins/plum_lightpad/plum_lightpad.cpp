#include <plum_lightpad.h>

plum_lightpad::plum_lightpad(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Plum Lightpad");
	manifest.insert("domain","plum_lightpad");
}

plum_lightpad::~plum_lightpad()
{
}

void plum_lightpad::init()
{
}

void plum_lightpad::async_setup()
{
}


void plum_lightpad::cleanup()
{
}


void plum_lightpad::new_load()
{
}


void plum_lightpad::new_lightpad()
{
}


