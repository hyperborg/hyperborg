#include <google.h>

google::google(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Calendars");
	manifest.insert("domain","google");
}

google::~google()
{
}

void google::init()
{
}

void google::do_authentication()
{
}


void google::step2_exchange()
{
}


void google::setup()
{
}


void google::check_correct_scopes()
{
}


void google::setup_services()
{
}


void google::_found_calendar()
{
}


void google::_scan_for_calendars()
{
}


void google::_add_event()
{
}


void google::do_setup()
{
}


void google::__init__()
{
}


void google::get_calendar_info()
{
}


void google::load_config()
{
}


void google::update_config()
{
}


