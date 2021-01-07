#include <zabbix.h>

zabbix::zabbix(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Zabbix");
	manifest.insert("domain","zabbix");
}

zabbix::~zabbix()
{
}

void zabbix::init()
{
}

void zabbix::setup()
{
}


