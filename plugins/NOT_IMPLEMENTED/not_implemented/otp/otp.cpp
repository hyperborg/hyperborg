#include <otp.h>

otp::otp(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","One-Time Password (OTP)");
	manifest.insert("domain","otp");
}

otp::~otp()
{
}

void otp::init()
{
}


