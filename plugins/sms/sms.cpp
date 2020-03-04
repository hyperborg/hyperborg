#include <sms.h>

sms::sms()
{
    	manifest.insert("domain","sms");
	manifest.insert("name","SMS notifications via GSM-modem");
}

sms::~sms()
{
}

void sms:: async_setup()
{
}


