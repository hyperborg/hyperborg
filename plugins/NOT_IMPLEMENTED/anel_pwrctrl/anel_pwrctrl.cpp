#include <anel_pwrctrl.h>

anel_pwrctrl::anel_pwrctrl(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Anel NET-PwrCtrl");
	manifest.insert("domain","anel_pwrctrl");
}

anel_pwrctrl::~anel_pwrctrl()
{
}

void anel_pwrctrl::init()
{
}


