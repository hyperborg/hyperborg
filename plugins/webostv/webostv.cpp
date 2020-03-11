#include <webostv.h>

webostv::webostv(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LG webOS Smart TV");
	manifest.insert("domain","webostv");
}

webostv::~webostv()
{
}

void webostv::init()
{
}

void webostv::async_setup()
{
}


void webostv::async_service_handler()
{
}


void webostv::async_setup_tv()
{
}


void webostv::async_connect()
{
}


void webostv::async_setup_tv_finalize()
{
}


void webostv::async_on_stop()
{
}


void webostv::async_request_configuration()
{
}


void webostv::lgtv_configuration_callback()
{
}


