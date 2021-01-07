#include <jewish_calendar.h>

jewish_calendar::jewish_calendar(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Jewish Calendar");
	manifest.insert("domain","jewish_calendar");
}

jewish_calendar::~jewish_calendar()
{
}

void jewish_calendar::init()
{
}

void jewish_calendar::async_setup()
{
}


