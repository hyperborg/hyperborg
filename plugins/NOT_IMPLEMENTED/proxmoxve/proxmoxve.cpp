#include <proxmoxve.h>

proxmoxve::proxmoxve(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Proxmox VE");
	manifest.insert("domain","proxmoxve");
}

proxmoxve::~proxmoxve()
{
}

void proxmoxve::init()
{
}

void proxmoxve::setup()
{
}


void proxmoxve::__init__()
{
}


void proxmoxve::build_client()
{
}


void proxmoxve::get_api_client()
{
}


