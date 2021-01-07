#include <asterisk_cdr.h>

asterisk_cdr::asterisk_cdr(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Asterisk Call Detail Records");
	manifest.insert("domain","asterisk_cdr");
}

asterisk_cdr::~asterisk_cdr()
{
}

void asterisk_cdr::init()
{
}


