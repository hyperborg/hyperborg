#include <lcn.h>

lcn::lcn(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LCN");
	manifest.insert("domain","lcn");
}

lcn::~lcn()
{
}

void lcn::init()
{
}

void lcn::async_setup()
{
}


void lcn::__init__()
{
}


void lcn::should_poll()
{
}


void lcn::async_added_to_hass()
{
}


void lcn::input_received()
{
}


