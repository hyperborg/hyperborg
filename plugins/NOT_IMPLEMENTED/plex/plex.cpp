#include <plex.h>

plex::plex(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Plex Media Server");
	manifest.insert("domain","plex");
}

plex::~plex()
{
}

void plex::init()
{
}

void plex::async_setup()
{
}


void plex::_async_setup_plex()
{
}


void plex::async_setup_entry()
{
}


void plex::update_plex()
{
}


void plex::start_websocket_session()
{
}


void plex::close_websocket_session()
{
}


void plex::async_unload_entry()
{
}


void plex::async_options_updated()
{
}


