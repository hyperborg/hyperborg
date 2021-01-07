#include <pulseaudio_loopback.h>

pulseaudio_loopback::pulseaudio_loopback(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","PulseAudio Loopback");
	manifest.insert("domain","pulseaudio_loopback");
}

pulseaudio_loopback::~pulseaudio_loopback()
{
}

void pulseaudio_loopback::init()
{
}


