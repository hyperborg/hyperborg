#include <sms.h>

sms::sms(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SMS notifications via GSM-modem");
	manifest.insert("domain","sms");
}

sms::~sms()
{
}

void sms::init()
{
}

void sms::async_setup()
{
}


