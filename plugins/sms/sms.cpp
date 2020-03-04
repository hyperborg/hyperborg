#include <sms.h>

sms::sms()
{
    	manifest.insert("name","SMS notifications via GSM-modem");
	manifest.insert("domain","sms");
}

sms::~sms()
{
}

void sms:: async_setup()
{
}


