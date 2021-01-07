#include <rss_feed_template.h>

rss_feed_template::rss_feed_template(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","RSS Feed Template");
	manifest.insert("domain","rss_feed_template");
}

rss_feed_template::~rss_feed_template()
{
}

void rss_feed_template::init()
{
}

void rss_feed_template::setup()
{
}


void rss_feed_template::__init__()
{
}


