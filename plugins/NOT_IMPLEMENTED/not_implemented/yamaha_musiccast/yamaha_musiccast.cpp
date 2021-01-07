#include <yamaha_musiccast.h>

yamaha_musiccast::yamaha_musiccast(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Yamaha MusicCast");
	manifest.insert("domain","yamaha_musiccast");
}

yamaha_musiccast::~yamaha_musiccast()
{
}

void yamaha_musiccast::init()
{
}


