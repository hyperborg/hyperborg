#include <elgato.h>

elgato::elgato(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Elgato Key Light");
	manifest.insert("domain","elgato");
}

elgato::~elgato()
{
}

void elgato::init()
{
}

void elgato::async_setup()
{
}


void elgato::async_setup_entry()
{
}


void elgato::async_unload_entry()
{
}


