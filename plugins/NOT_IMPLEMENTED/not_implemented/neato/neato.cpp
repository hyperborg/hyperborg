#include <neato.h>

neato::neato(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Neato Botvac");
	manifest.insert("domain","neato");
}

neato::~neato()
{
}

void neato::init()
{
}

void neato::async_setup()
{
}


void neato::async_setup_entry()
{
}


void neato::async_unload_entry()
{
}


void neato::__init__()
{
}


void neato::login()
{
}


void neato::update_robots()
{
}


void neato::download_map()
{
}


