#include <samsungtv.h>

samsungtv::samsungtv(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Samsung Smart TV");
	manifest.insert("domain","samsungtv");
}

samsungtv::~samsungtv()
{
}

void samsungtv::init()
{
}

void samsungtv::ensure_unique_hosts()
{
}


void samsungtv::async_setup()
{
}


void samsungtv::async_setup_entry()
{
}


