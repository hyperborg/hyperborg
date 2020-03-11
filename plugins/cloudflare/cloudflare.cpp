#include <cloudflare.h>

cloudflare::cloudflare(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Cloudflare");
	manifest.insert("domain","cloudflare");
}

cloudflare::~cloudflare()
{
}

void cloudflare::init()
{
}

void cloudflare::setup()
{
}


void cloudflare::update_records_interval()
{
}


void cloudflare::update_records_service()
{
}


void cloudflare::_update_cloudflare()
{
}


