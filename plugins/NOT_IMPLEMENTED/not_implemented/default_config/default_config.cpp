#include <default_config.h>

default_config::default_config(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Default Config");
	manifest.insert("domain","default_config");
}

default_config::~default_config()
{
}

void default_config::init()
{
}

void default_config::async_setup()
{
}


