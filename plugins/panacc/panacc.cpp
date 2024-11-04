#include <panacc.h>

PanaCC::PanaCC(QObject *parent) : HyPluginInterface(), HDevice(parent)
{
    loadConfiguration("");
}

PanaCC::~PanaCC()
{
}

void PanaCC::loadConfiguration(QString str)
{
}

