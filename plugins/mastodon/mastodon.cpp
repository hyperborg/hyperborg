#include <mastodon.h>

mastodon::mastodon(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Mastodon");
	manifest.insert("domain","mastodon");
}

mastodon::~mastodon()
{
}

void mastodon::init()
{
}


