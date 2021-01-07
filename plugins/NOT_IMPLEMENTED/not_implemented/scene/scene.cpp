#include <scene.h>

scene::scene(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Scenes");
	manifest.insert("domain","scene");
}

scene::~scene()
{
}

void scene::init()
{
}

void scene::_hass_domain_validator()
{
}


void scene::_platform_validator()
{
}


void scene::async_setup()
{
}


void scene::async_setup_entry()
{
}


void scene::async_unload_entry()
{
}


void scene::should_poll()
{
}


void scene::state()
{
}


void scene::activate()
{
}


void scene::async_activate()
{
}


