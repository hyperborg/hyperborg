#include <yandex_transport.h>

yandex_transport::yandex_transport(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Yandex Transport");
	manifest.insert("domain","yandex_transport");
}

yandex_transport::~yandex_transport()
{
}

void yandex_transport::init()
{
}


