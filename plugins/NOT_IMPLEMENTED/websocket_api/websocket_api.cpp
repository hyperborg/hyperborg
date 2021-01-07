#include <websocket_api.h>

websocket_api::websocket_api(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Home Asssitant WebSocket API");
	manifest.insert("domain","websocket_api");
}

websocket_api::~websocket_api()
{
}

void websocket_api::init()
{
}

void websocket_api::async_register_command()
{
}


void websocket_api::async_setup()
{
}


