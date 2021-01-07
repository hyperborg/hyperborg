#include <heatmiser.h>

heatmiser::heatmiser(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Heatmiser");
	manifest.insert("domain","heatmiser");
}

heatmiser::~heatmiser()
{
}

void heatmiser::init()
{
}


