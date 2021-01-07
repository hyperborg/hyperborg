#include <snmp.h>

snmp::snmp(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SNMP");
	manifest.insert("domain","snmp");
}

snmp::~snmp()
{
}

void snmp::init()
{
}


