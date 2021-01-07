#include <discord.h>

discord::discord(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Discord");
	manifest.insert("domain","discord");
}

discord::~discord()
{
}

void discord::init()
{
}


