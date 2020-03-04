#include <shell_command.h>

shell_command::shell_command()
{
    	manifest.insert("domain","shell_command");
	manifest.insert("name","Shell Command");
}

shell_command::~shell_command()
{
}

void shell_command:: async_setup()
{
}


void shell_command:: async_service_handler()
{
}


