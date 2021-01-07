#include <twilio_call.h>

twilio_call::twilio_call(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Twilio Call");
	manifest.insert("domain","twilio_call");
}

twilio_call::~twilio_call()
{
}

void twilio_call::init()
{
}


