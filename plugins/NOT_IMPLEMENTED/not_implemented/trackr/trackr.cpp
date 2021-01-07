#include <trackr.h>

trackr::trackr(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","TrackR");
	manifest.insert("domain","trackr");
}

trackr::~trackr()
{
}

void trackr::init()
{
}


