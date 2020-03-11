#include <lirc.h>

lirc::lirc(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LIRC");
	manifest.insert("domain","lirc");
}

lirc::~lirc()
{
}

void lirc::init()
{
}

void lirc::setup()
{
}


void lirc::_start_lirc()
{
}


void lirc::_stop_lirc()
{
}


void lirc::__init__()
{
}


void lirc::run()
{
}


