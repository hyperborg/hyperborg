#include <smhi.h>

smhi::smhi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SMHI");
	manifest.insert("domain","smhi");
}

smhi::~smhi()
{
}

void smhi::init()
{
}

void smhi::async_setup()
{
}


void smhi::async_setup_entry()
{
}


void smhi::async_unload_entry()
{
}


