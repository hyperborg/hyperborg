#include <rmvtransport.h>

rmvtransport::rmvtransport(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","RMV");
	manifest.insert("domain","rmvtransport");
}

rmvtransport::~rmvtransport()
{
}

void rmvtransport::init()
{
}


