#include <pushover.h>

pushover::pushover(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Pushover");
	manifest.insert("domain","pushover");
}

pushover::~pushover()
{
}

void pushover::init()
{
}


