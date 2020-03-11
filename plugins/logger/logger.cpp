#include <logger.h>

logger::logger(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Logger");
	manifest.insert("domain","logger");
}

logger::~logger()
{
}

void logger::init()
{
}

void logger::__init__()
{
}


void logger::filter()
{
}


void logger::async_setup()
{
}


void logger::set_default_log_level()
{
}


void logger::set_log_levels()
{
}


void logger::async_service_handler()
{
}


