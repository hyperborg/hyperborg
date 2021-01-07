#include <tensorflow.h>

tensorflow::tensorflow(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","TensorFlow");
	manifest.insert("domain","tensorflow");
}

tensorflow::~tensorflow()
{
}

void tensorflow::init()
{
}


