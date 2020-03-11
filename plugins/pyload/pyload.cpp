#include <pyload.h>

pyload::pyload(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","pyLoad");
	manifest.insert("domain","pyload");
}

pyload::~pyload()
{
}

void pyload::init()
{
}


