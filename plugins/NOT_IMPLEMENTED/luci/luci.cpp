#include <luci.h>

luci::luci(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OpenWRT (luci)");
	manifest.insert("domain","luci");
}

luci::~luci()
{
}

void luci::init()
{
}


