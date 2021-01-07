#include <universal.h>

universal::universal(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Universal Media Player");
	manifest.insert("domain","universal");
}

universal::~universal()
{
}

void universal::init()
{
}


