#include <remote.h>

remote::remote(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Remote");
	manifest.insert("domain","remote");
}

remote::~remote()
{
}

void remote::init()
{
}

void remote::is_on()
{
}


void remote::async_setup()
{
}


void remote::supported_features()
{
}


void remote::send_command()
{
}


void remote::async_send_command()
{
}


void remote::learn_command()
{
}


void remote::async_learn_command()
{
}


