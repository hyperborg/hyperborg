#include <ipma.h>

ipma::ipma(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Instituto Português do Mar e Atmosfera (IPMA)");
	manifest.insert("domain","ipma");
}

ipma::~ipma()
{
}

void ipma::init()
{
}

void ipma::async_setup()
{
}


void ipma::async_setup_entry()
{
}


void ipma::async_unload_entry()
{
}


