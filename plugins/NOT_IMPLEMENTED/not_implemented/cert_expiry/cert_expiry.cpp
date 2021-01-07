#include <cert_expiry.h>

cert_expiry::cert_expiry(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Certificate Expiry");
	manifest.insert("domain","cert_expiry");
}

cert_expiry::~cert_expiry()
{
}

void cert_expiry::init()
{
}

void cert_expiry::async_setup()
{
}


void cert_expiry::async_setup_entry()
{
}


void cert_expiry::async_unload_entry()
{
}


