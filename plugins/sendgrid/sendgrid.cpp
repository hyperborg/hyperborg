#include <sendgrid.h>

sendgrid::sendgrid(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SendGrid");
	manifest.insert("domain","sendgrid");
}

sendgrid::~sendgrid()
{
}

void sendgrid::init()
{
}


