#include "hplugin.h"

HPlugin::HPlugin(QObject *parent) : QObject(parent)
{}

HPlugin::~HPlugin()
{
}

void HPlugin::setHFS(HFS_Interface* h) 
{
    hfs = h; 
}

void HPlugin::log(int severity, QString logline)
{
    emit signal_log(severity, logline, _id);
}

void HPlugin::loadConfiguration(QString str)
{
}


