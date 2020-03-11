#include <updater.h>

updater::updater(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Updater");
	manifest.insert("domain","updater");
}

updater::~updater()
{
}

void updater::init()
{
}

void updater::__init__()
{
}


void updater::_create_uuid()
{
}


void updater::_load_uuid()
{
}


void updater::async_setup()
{
}


void updater::check_new_version()
{
}


void updater::get_newest_version()
{
}


