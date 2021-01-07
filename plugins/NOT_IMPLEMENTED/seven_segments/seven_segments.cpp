#include <seven_segments.h>

seven_segments::seven_segments(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Seven Segments OCR");
	manifest.insert("domain","seven_segments");
}

seven_segments::~seven_segments()
{
}

void seven_segments::init()
{
}


