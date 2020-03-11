#include <openalpr_local.h>

openalpr_local::openalpr_local(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OpenALPR Local");
	manifest.insert("domain","openalpr_local");
}

openalpr_local::~openalpr_local()
{
}

void openalpr_local::init()
{
}


