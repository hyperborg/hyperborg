#include <rest_command.h>

rest_command::rest_command()
{
    	manifest.insert("domain","rest_command");
	manifest.insert("name","RESTful Command");
}

rest_command::~rest_command()
{
}

void rest_command:: async_setup()
{
}


void rest_command::async_register_rest_command()
{
}


void rest_command:: async_service_handler()
{
}


