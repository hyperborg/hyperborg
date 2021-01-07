#include <ffmpeg_motion.h>

ffmpeg_motion::ffmpeg_motion(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","FFmpeg Motion");
	manifest.insert("domain","ffmpeg_motion");
}

ffmpeg_motion::~ffmpeg_motion()
{
}

void ffmpeg_motion::init()
{
}


