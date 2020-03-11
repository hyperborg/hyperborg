#include <harmony.h>

harmony::harmony(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Logitech Harmony Hub");
	manifest.insert("domain","harmony");
}

harmony::~harmony()
{
}

void harmony::init()
{
}


