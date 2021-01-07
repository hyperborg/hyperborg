#include <ue_smart_radio.h>

ue_smart_radio::ue_smart_radio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Logitech UE Smart Radio");
	manifest.insert("domain","ue_smart_radio");
}

ue_smart_radio::~ue_smart_radio()
{
}

void ue_smart_radio::init()
{
}


