#include <message_bird.h>

message_bird::message_bird(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MessageBird");
	manifest.insert("domain","message_bird");
}

message_bird::~message_bird()
{
}

void message_bird::init()
{
}


