#include <rest_command.h>

rest_command::rest_command(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","RESTful Command");
	manifest.insert("domain","rest_command");
}

rest_command::~rest_command()
{
}

void rest_command::init()
{
}

void rest_command::async_setup()
{
}


void rest_command::async_register_rest_command()
{
}


void rest_command::async_service_handler()
{
}


