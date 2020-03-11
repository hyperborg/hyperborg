#include <history_stats.h>

history_stats::history_stats(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","History Stats");
	manifest.insert("domain","history_stats");
}

history_stats::~history_stats()
{
}

void history_stats::init()
{
}


