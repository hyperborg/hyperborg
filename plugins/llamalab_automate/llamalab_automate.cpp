#include <llamalab_automate.h>

llamalab_automate::llamalab_automate(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LlamaLab Automate");
	manifest.insert("domain","llamalab_automate");
}

llamalab_automate::~llamalab_automate()
{
}

void llamalab_automate::init()
{
}


