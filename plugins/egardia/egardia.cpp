#include <egardia.h>

egardia::egardia(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Egardia");
	manifest.insert("domain","egardia");
}

egardia::~egardia()
{
}

void egardia::init()
{
}

void egardia::setup()
{
}


void egardia::handle_stop_event()
{
}


