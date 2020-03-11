#include <garmin_connect.h>

garmin_connect::garmin_connect(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Garmin Connect");
	manifest.insert("domain","garmin_connect");
}

garmin_connect::~garmin_connect()
{
}

void garmin_connect::init()
{
}

void garmin_connect::async_setup()
{
}


void garmin_connect::async_setup_entry()
{
}


void garmin_connect::async_unload_entry()
{
}


void garmin_connect::__init__()
{
}


void garmin_connect::async_update()
{
}


