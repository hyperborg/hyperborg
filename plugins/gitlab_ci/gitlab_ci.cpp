#include <gitlab_ci.h>

gitlab_ci::gitlab_ci(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","GitLab-CI");
	manifest.insert("domain","gitlab_ci");
}

gitlab_ci::~gitlab_ci()
{
}

void gitlab_ci::init()
{
}


