#include <voicerss.h>

voicerss::voicerss(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","VoiceRSS");
	manifest.insert("domain","voicerss");
}

voicerss::~voicerss()
{
}

void voicerss::init()
{
}


