#include <fortigate.h>

fortigate::fortigate(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","FortiGate");
	manifest.insert("domain","fortigate");
}

fortigate::~fortigate()
{
}

void fortigate::init()
{
}

void fortigate::async_setup()
{
}


void fortigate::async_setup_fortigate()
{
}


void fortigate::close_fgt()
{
}


