#include <clicksend_tts.h>

clicksend_tts::clicksend_tts(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ClickSend TTS");
	manifest.insert("domain","clicksend_tts");
}

clicksend_tts::~clicksend_tts()
{
}

void clicksend_tts::init()
{
}


