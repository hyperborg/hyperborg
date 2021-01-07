#include <synology_chat.h>

synology_chat::synology_chat(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Synology Chat");
	manifest.insert("domain","synology_chat");
}

synology_chat::~synology_chat()
{
}

void synology_chat::init()
{
}


