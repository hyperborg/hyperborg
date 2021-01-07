#include <workday.h>

workday::workday(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Workday");
	manifest.insert("domain","workday");
}

workday::~workday()
{
}

void workday::init()
{
}


