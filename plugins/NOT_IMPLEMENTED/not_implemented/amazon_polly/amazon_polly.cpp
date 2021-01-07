#include <amazon_polly.h>

amazon_polly::amazon_polly(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Amazon Polly");
	manifest.insert("domain","amazon_polly");
}

amazon_polly::~amazon_polly()
{
}

void amazon_polly::init()
{
}


