#include <dlna_dmr.h>

dlna_dmr::dlna_dmr(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DLNA Digital Media Renderer");
	manifest.insert("domain","dlna_dmr");
}

dlna_dmr::~dlna_dmr()
{
}

void dlna_dmr::init()
{
}


