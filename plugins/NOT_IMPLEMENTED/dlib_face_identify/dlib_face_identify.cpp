#include <dlib_face_identify.h>

dlib_face_identify::dlib_face_identify(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Dlib Face Identify");
	manifest.insert("domain","dlib_face_identify");
}

dlib_face_identify::~dlib_face_identify()
{
}

void dlib_face_identify::init()
{
}


