#include <slack.h>

slack::slack(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Slack");
	manifest.insert("domain","slack");
}

slack::~slack()
{
}

void slack::init()
{
}


