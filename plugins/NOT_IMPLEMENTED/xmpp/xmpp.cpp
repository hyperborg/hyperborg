#include <xmpp.h>

xmpp::xmpp(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Jabber (XMPP)");
	manifest.insert("domain","xmpp");
}

xmpp::~xmpp()
{
}

void xmpp::init()
{
}


