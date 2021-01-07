#include <rflink.h>

rflink::rflink(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","RFLink");
	manifest.insert("domain","rflink");
}

rflink::~rflink()
{
}

void rflink::init()
{
}

void rflink::identify_event_type()
{
}


void rflink::async_setup()
{
}


void rflink::async_send_command()
{
}


void rflink::event_callback()
{
}


void rflink::reconnect()
{
}


void rflink::connect()
{
}


void rflink::__init__()
{
}


void rflink::handle_event_callback()
{
}


void rflink::_handle_event()
{
}


void rflink::should_poll()
{
}


void rflink::is_on()
{
}


void rflink::assumed_state()
{
}


void rflink::available()
{
}


void rflink::_availability_callback()
{
}


void rflink::async_added_to_hass()
{
}


void rflink::set_rflink_protocol()
{
}


void rflink::is_connected()
{
}


void rflink::send_command()
{
}


void rflink::_async_handle_command()
{
}


void rflink::cancel_queued_send_commands()
{
}


void rflink::_async_send_command()
{
}


void rflink::async_turn_on()
{
}


void rflink::async_turn_off()
{
}


