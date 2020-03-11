#include <google_pubsub.h>

google_pubsub::google_pubsub(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Pub/Sub");
	manifest.insert("domain","google_pubsub");
}

google_pubsub::~google_pubsub()
{
}

void google_pubsub::init()
{
}

void google_pubsub::setup()
{
}


void google_pubsub::send_to_pubsub()
{
}


