#include <etherscan.h>

etherscan::etherscan(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Etherscan");
	manifest.insert("domain","etherscan");
}

etherscan::~etherscan()
{
}

void etherscan::init()
{
}


