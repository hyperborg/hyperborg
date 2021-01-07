#include <yandextts.h>

yandextts::yandextts(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Yandex TTS");
	manifest.insert("domain","yandextts");
}

yandextts::~yandextts()
{
}

void yandextts::init()
{
}


