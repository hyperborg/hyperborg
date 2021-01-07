#include <twilio_sms.h>

twilio_sms::twilio_sms(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Twilio SMS");
	manifest.insert("domain","twilio_sms");
}

twilio_sms::~twilio_sms()
{
}

void twilio_sms::init()
{
}


