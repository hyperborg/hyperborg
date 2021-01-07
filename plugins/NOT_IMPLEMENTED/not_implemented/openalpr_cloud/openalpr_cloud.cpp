#include <openalpr_cloud.h>

openalpr_cloud::openalpr_cloud(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OpenALPR Cloud");
	manifest.insert("domain","openalpr_cloud");
}

openalpr_cloud::~openalpr_cloud()
{
}

void openalpr_cloud::init()
{
}


