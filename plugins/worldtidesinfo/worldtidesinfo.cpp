#include <worldtidesinfo.h>

worldtidesinfo::worldtidesinfo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","World Tides");
	manifest.insert("domain","worldtidesinfo");
}

worldtidesinfo::~worldtidesinfo()
{
}

void worldtidesinfo::init()
{
}


