#include <thinkingcleaner.h>

thinkingcleaner::thinkingcleaner(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Thinking Cleaner");
	manifest.insert("domain","thinkingcleaner");
}

thinkingcleaner::~thinkingcleaner()
{
}

void thinkingcleaner::init()
{
}


