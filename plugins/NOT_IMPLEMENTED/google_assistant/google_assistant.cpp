#include <google_assistant.h>

google_assistant::google_assistant(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Assistant");
	manifest.insert("domain","google_assistant");
}

google_assistant::~google_assistant()
{
}

void google_assistant::init()
{
}

void google_assistant::_check_report_state()
{
}


void google_assistant::async_setup()
{
}


void google_assistant::request_sync_service_handler()
{
}


