#include <emoncms_history.h>

emoncms_history::emoncms_history(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Emoncms History");
	manifest.insert("domain","emoncms_history");
}

emoncms_history::~emoncms_history()
{
}

void emoncms_history::init()
{
}

void emoncms_history::setup()
{
}


void emoncms_history::send_data()
{
}


void emoncms_history::update_emoncms()
{
}


