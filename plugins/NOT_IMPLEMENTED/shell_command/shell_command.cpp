#include <shell_command.h>

shell_command::shell_command(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Shell Command");
	manifest.insert("domain","shell_command");
}

shell_command::~shell_command()
{
}

void shell_command::init()
{
}

void shell_command::async_setup()
{
}


void shell_command::async_service_handler()
{
}


