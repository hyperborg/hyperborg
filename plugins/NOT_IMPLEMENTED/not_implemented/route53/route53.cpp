#include <route53.h>

route53::route53(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","AWS Route53");
	manifest.insert("domain","route53");
}

route53::~route53()
{
}

void route53::init()
{
}

void route53::setup()
{
}


void route53::update_records_interval()
{
}


void route53::update_records_service()
{
}


void route53::_update_route53()
{
}


