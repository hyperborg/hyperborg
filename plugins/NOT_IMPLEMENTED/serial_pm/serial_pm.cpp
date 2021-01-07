#include <serial_pm.h>

serial_pm::serial_pm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Serial Particulate Matter");
	manifest.insert("domain","serial_pm");
}

serial_pm::~serial_pm()
{
}

void serial_pm::init()
{
}


