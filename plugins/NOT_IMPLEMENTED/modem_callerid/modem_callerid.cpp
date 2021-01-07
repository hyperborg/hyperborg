#include <modem_callerid.h>

modem_callerid::modem_callerid(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Modem Caller ID");
	manifest.insert("domain","modem_callerid");
}

modem_callerid::~modem_callerid()
{
}

void modem_callerid::init()
{
}


