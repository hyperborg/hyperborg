#include <eliqonline.h>

eliqonline::eliqonline(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Eliqonline");
	manifest.insert("domain","eliqonline");
}

eliqonline::~eliqonline()
{
}

void eliqonline::init()
{
}


