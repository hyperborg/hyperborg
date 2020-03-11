#include <decora_wifi.h>

decora_wifi::decora_wifi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Leviton Decora Wi-Fi");
	manifest.insert("domain","decora_wifi");
}

decora_wifi::~decora_wifi()
{
}

void decora_wifi::init()
{
}


