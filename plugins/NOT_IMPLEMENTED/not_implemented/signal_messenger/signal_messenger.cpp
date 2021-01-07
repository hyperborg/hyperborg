#include <signal_messenger.h>

signal_messenger::signal_messenger(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Signal Messenger");
	manifest.insert("domain","signal_messenger");
}

signal_messenger::~signal_messenger()
{
}

void signal_messenger::init()
{
}


