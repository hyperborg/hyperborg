#include <serial.h>

serial::serial(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Serial");
	manifest.insert("domain","serial");
}

serial::~serial()
{
}

void serial::init()
{
}


