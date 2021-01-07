#include <google_cloud.h>

google_cloud::google_cloud(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Cloud Platform");
	manifest.insert("domain","google_cloud");
}

google_cloud::~google_cloud()
{
}

void google_cloud::init()
{
}


