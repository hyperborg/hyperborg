#include <splunk.h>

splunk::splunk(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Splunk");
	manifest.insert("domain","splunk");
}

splunk::~splunk()
{
}

void splunk::init()
{
}

void splunk::post_request()
{
}


void splunk::setup()
{
}


void splunk::splunk_event_listener()
{
}


