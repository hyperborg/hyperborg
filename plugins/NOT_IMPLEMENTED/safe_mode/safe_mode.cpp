#include <safe_mode.h>

safe_mode::safe_mode(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Safe Mode");
	manifest.insert("domain","safe_mode");
}

safe_mode::~safe_mode()
{
}

void safe_mode::init()
{
}

void safe_mode::async_setup()
{
}


