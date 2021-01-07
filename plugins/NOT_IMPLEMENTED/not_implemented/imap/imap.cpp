#include <imap.h>

imap::imap(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","IMAP");
	manifest.insert("domain","imap");
}

imap::~imap()
{
}

void imap::init()
{
}


