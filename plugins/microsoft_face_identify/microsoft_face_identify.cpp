#include <microsoft_face_identify.h>

microsoft_face_identify::microsoft_face_identify(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Microsoft Face Identify");
	manifest.insert("domain","microsoft_face_identify");
}

microsoft_face_identify::~microsoft_face_identify()
{
}

void microsoft_face_identify::init()
{
}


