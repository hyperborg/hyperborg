#include <bayesian.h>

bayesian::bayesian(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bayesian");
	manifest.insert("domain","bayesian");
}

bayesian::~bayesian()
{
}

void bayesian::init()
{
}


