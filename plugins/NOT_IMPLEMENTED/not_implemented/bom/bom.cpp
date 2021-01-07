#include <bom.h>

bom::bom(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Australian Bureau of Meteorology (BOM)");
	manifest.insert("domain","bom");
}

bom::~bom()
{
}

void bom::init()
{
}


