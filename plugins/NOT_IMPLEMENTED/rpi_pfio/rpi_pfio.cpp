#include <rpi_pfio.h>

rpi_pfio::rpi_pfio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","PiFace Digital I/O (PFIO)");
	manifest.insert("domain","rpi_pfio");
}

rpi_pfio::~rpi_pfio()
{
}

void rpi_pfio::init()
{
}

void rpi_pfio::setup()
{
}


void rpi_pfio::cleanup_pfio()
{
}


void rpi_pfio::prepare_pfio()
{
}


void rpi_pfio::write_output()
{
}


void rpi_pfio::read_input()
{
}


void rpi_pfio::edge_detect()
{
}


void rpi_pfio::activate_listener()
{
}


