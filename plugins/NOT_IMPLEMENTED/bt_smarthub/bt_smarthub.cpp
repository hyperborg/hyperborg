#include <bt_smarthub.h>

bt_smarthub::bt_smarthub(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","BT Smart Hub");
	manifest.insert("domain","bt_smarthub");
}

bt_smarthub::~bt_smarthub()
{
}

void bt_smarthub::init()
{
}


