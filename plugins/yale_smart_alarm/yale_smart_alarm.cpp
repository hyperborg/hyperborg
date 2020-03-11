#include <yale_smart_alarm.h>

yale_smart_alarm::yale_smart_alarm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Yale Smart Living");
	manifest.insert("domain","yale_smart_alarm");
}

yale_smart_alarm::~yale_smart_alarm()
{
}

void yale_smart_alarm::init()
{
}


