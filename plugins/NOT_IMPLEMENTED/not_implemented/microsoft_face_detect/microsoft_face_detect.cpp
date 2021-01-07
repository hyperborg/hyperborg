#include <microsoft_face_detect.h>

microsoft_face_detect::microsoft_face_detect(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Microsoft Face Detect");
	manifest.insert("domain","microsoft_face_detect");
}

microsoft_face_detect::~microsoft_face_detect()
{
}

void microsoft_face_detect::init()
{
}


