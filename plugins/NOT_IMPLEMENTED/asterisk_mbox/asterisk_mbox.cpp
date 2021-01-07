#include <asterisk_mbox.h>

asterisk_mbox::asterisk_mbox(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Asterisk Voicemail");
	manifest.insert("domain","asterisk_mbox");
}

asterisk_mbox::~asterisk_mbox()
{
}

void asterisk_mbox::init()
{
}

void asterisk_mbox::setup()
{
}


void asterisk_mbox::__init__()
{
}


void asterisk_mbox::_discover_platform()
{
}


void asterisk_mbox::handle_data()
{
}


void asterisk_mbox::_request_messages()
{
}


void asterisk_mbox::_request_cdr()
{
}


