#include <travisci.h>

travisci::travisci(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Travis-CI");
	manifest.insert("domain","travisci");
}

travisci::~travisci()
{
}

void travisci::init()
{
}


