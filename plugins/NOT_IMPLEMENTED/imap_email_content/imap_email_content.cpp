#include <imap_email_content.h>

imap_email_content::imap_email_content(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","IMAP Email Content");
	manifest.insert("domain","imap_email_content");
}

imap_email_content::~imap_email_content()
{
}

void imap_email_content::init()
{
}


