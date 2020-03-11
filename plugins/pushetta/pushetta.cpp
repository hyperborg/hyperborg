#include <pushetta.h>

pushetta::pushetta(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Pushetta");
	manifest.insert("domain","pushetta");
}

pushetta::~pushetta()
{
}

void pushetta::init()
{
}


