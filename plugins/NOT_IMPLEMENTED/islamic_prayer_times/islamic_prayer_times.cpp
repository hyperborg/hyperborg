#include <islamic_prayer_times.h>

islamic_prayer_times::islamic_prayer_times(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Islamic Prayer Times");
	manifest.insert("domain","islamic_prayer_times");
}

islamic_prayer_times::~islamic_prayer_times()
{
}

void islamic_prayer_times::init()
{
}


