#include <gstreamer.h>

gstreamer::gstreamer(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","GStreamer");
	manifest.insert("domain","gstreamer");
}

gstreamer::~gstreamer()
{
}

void gstreamer::init()
{
}


