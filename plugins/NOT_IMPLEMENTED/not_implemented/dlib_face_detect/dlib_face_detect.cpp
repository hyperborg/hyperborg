#include <dlib_face_detect.h>

dlib_face_detect::dlib_face_detect(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Dlib Face Detect");
	manifest.insert("domain","dlib_face_detect");
}

dlib_face_detect::~dlib_face_detect()
{
}

void dlib_face_detect::init()
{
}


