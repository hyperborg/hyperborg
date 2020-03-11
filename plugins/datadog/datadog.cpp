#include <datadog.h>

datadog::datadog(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Datadog");
	manifest.insert("domain","datadog");
}

datadog::~datadog()
{
}

void datadog::init()
{
}

void datadog::setup()
{
}


void datadog::logbook_entry_listener()
{
}


void datadog::state_changed_listener()
{
}


