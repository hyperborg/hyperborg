#include <trafikverket_train.h>

trafikverket_train::trafikverket_train(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Trafikverket Train");
	manifest.insert("domain","trafikverket_train");
}

trafikverket_train::~trafikverket_train()
{
}

void trafikverket_train::init()
{
}


