#include <configurator.h>

configurator::configurator(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Configurator");
	manifest.insert("domain","configurator");
}

configurator::~configurator()
{
}

void configurator::init()
{
}

void configurator::async_request_config()
{
}


void configurator::request_config()
{
}


void configurator::async_notify_errors()
{
}


void configurator::notify_errors()
{
}


void configurator::async_request_done()
{
}


void configurator::request_done()
{
}


void configurator::async_setup()
{
}


void configurator::__init__()
{
}


void configurator::deferred_remove()
{
}


void configurator::async_handle_service_call()
{
}


void configurator::_generate_unique_id()
{
}


void configurator::_validate_request_id()
{
}


