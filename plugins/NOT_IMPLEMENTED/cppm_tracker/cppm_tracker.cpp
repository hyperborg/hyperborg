#include <cppm_tracker.h>

cppm_tracker::cppm_tracker(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Aruba ClearPass");
	manifest.insert("domain","cppm_tracker");
}

cppm_tracker::~cppm_tracker()
{
}

void cppm_tracker::init()
{
}


