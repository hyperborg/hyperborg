#include <spc.h>

spc::spc(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Vanderbilt SPC");
	manifest.insert("domain","spc");
}

spc::~spc()
{
}

void spc::init()
{
}

void spc::async_setup()
{
}


void spc::async_upate_callback()
{
}


