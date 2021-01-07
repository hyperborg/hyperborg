#include <tplink_lte.h>

tplink_lte::tplink_lte(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","TP-Link LTE");
	manifest.insert("domain","tplink_lte");
}

tplink_lte::~tplink_lte()
{
}

void tplink_lte::init()
{
}

void tplink_lte::get_modem_data()
{
}


void tplink_lte::async_setup()
{
}


void tplink_lte::_setup_lte()
{
}


void tplink_lte::cleanup_retry()
{
}


void tplink_lte::_login()
{
}


void tplink_lte::cleanup()
{
}


void tplink_lte::_retry_login()
{
}


