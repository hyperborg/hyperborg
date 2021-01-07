#include <onboarding.h>

onboarding::onboarding(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Home Assistant Onboarding");
	manifest.insert("domain","onboarding");
}

onboarding::~onboarding()
{
}

void onboarding::init()
{
}

void onboarding::_async_migrate_func()
{
}


void onboarding::async_is_onboarded()
{
}


void onboarding::async_is_user_onboarded()
{
}


void onboarding::async_setup()
{
}


