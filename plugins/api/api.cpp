#include <api.h>

api::api(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Home Assistant API");
	manifest.insert("domain","api");
}

api::~api()
{
}

void api::init()
{
}

void api::setup()
{
}


void api::forward_events()
{
}


void api::post()
{
}


void api::async_services_json()
{
}


void api::async_events_json()
{
}


