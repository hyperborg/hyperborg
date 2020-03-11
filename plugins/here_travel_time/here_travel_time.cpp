#include <here_travel_time.h>

here_travel_time::here_travel_time(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","HERE Travel Time");
	manifest.insert("domain","here_travel_time");
}

here_travel_time::~here_travel_time()
{
}

void here_travel_time::init()
{
}


