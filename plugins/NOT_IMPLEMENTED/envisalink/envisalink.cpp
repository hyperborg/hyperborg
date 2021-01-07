#include <envisalink.h>

envisalink::envisalink(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Envisalink");
	manifest.insert("domain","envisalink");
}

envisalink::~envisalink()
{
}

void envisalink::init()
{
}

void envisalink::async_setup()
{
}


void envisalink::login_fail_callback()
{
}


void envisalink::connection_fail_callback()
{
}


void envisalink::connection_success_callback()
{
}


void envisalink::zones_updated_callback()
{
}


void envisalink::alarm_data_updated_callback()
{
}


void envisalink::partition_updated_callback()
{
}


void envisalink::stop_envisalink()
{
}


void envisalink::handle_custom_function()
{
}


void envisalink::__init__()
{
}


void envisalink::should_poll()
{
}


