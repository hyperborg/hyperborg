#include <watson_tts.h>

watson_tts::watson_tts(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","IBM Watson TTS");
	manifest.insert("domain","watson_tts");
}

watson_tts::~watson_tts()
{
}

void watson_tts::init()
{
}


