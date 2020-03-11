#include <zamg.h>

zamg::zamg(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Zentralanstalt für Meteorologie und Geodynamik (ZAMG)");
	manifest.insert("domain","zamg");
}

zamg::~zamg()
{
}

void zamg::init()
{
}


