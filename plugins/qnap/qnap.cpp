#include <qnap.h>

qnap::qnap(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","QNAP");
	manifest.insert("domain","qnap");
}

qnap::~qnap()
{
}

void qnap::init()
{
}


