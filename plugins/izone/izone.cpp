#include <izone.h>

izone::izone(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","iZone");
	manifest.insert("domain","izone");
}

izone::~izone()
{
}

void izone::init()
{
}

void izone::async_setup()
{
}


void izone::async_setup_entry()
{
}


void izone::async_unload_entry()
{
}


