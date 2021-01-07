#include <aten_pe.h>

aten_pe::aten_pe(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ATEN Rack PDU");
	manifest.insert("domain","aten_pe");
}

aten_pe::~aten_pe()
{
}

void aten_pe::init()
{
}


