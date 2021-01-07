#include <cisco_webex_teams.h>

cisco_webex_teams::cisco_webex_teams(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Cisco Webex Teams");
	manifest.insert("domain","cisco_webex_teams");
}

cisco_webex_teams::~cisco_webex_teams()
{
}

void cisco_webex_teams::init()
{
}


