#include <enigma2.h>

enigma2::enigma2(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Enigma2 (OpenWebif)");
	manifest.insert("domain","enigma2");
}

enigma2::~enigma2()
{
}

void enigma2::init()
{
}


