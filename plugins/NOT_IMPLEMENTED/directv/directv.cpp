#include <directv.h>

directv::directv(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DirecTV");
	manifest.insert("domain","directv");
}

directv::~directv()
{
}

void directv::init()
{
}


