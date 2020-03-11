#include <time_date.h>

time_date::time_date(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Time & Date");
	manifest.insert("domain","time_date");
}

time_date::~time_date()
{
}

void time_date::init()
{
}


