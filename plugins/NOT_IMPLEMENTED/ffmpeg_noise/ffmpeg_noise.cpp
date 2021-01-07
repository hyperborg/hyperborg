#include <ffmpeg_noise.h>

ffmpeg_noise::ffmpeg_noise(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","FFmpeg Noise");
	manifest.insert("domain","ffmpeg_noise");
}

ffmpeg_noise::~ffmpeg_noise()
{
}

void ffmpeg_noise::init()
{
}


