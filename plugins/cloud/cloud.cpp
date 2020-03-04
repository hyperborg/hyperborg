#include <cloud.h>

cloud::cloud()
{
    	manifest.insert("name","Home Assistant Cloud");
	manifest.insert("domain","cloud");
}

cloud::~cloud()
{
}

void cloud::async_is_logged_in()
{
}


void cloud::async_active_subscription()
{
}


void cloud::async_create_cloudhook()
{
}


void cloud::async_delete_cloudhook()
{
}


void cloud::async_remote_ui_url()
{
}


void cloud::is_cloudhook_request()
{
}


void cloud::async_setup()
{
}


void cloud::_startup()
{
}


void cloud::_shutdown()
{
}


void cloud::_service_handler()
{
}


void cloud::_on_connect()
{
}


