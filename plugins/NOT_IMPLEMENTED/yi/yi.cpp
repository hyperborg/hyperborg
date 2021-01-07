#include <yi.h>

yi::yi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Yi Home Cameras");
	manifest.insert("domain","yi");
}

yi::~yi()
{
}

void yi::init()
{
}


