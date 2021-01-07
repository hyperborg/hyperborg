#include <fail2ban.h>

fail2ban::fail2ban(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Fail2Ban");
	manifest.insert("domain","fail2ban");
}

fail2ban::~fail2ban()
{
}

void fail2ban::init()
{
}


