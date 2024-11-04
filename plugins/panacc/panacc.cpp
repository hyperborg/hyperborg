#include <panacc.h>

PanaCC::PanaCC(QObject *parent) : HPlugin(parent), HyPluginInterface()
{
    loadConfiguration("");
}

PanaCC::~PanaCC()
{
}

void PanaCC::loadConfiguration(QString str)
{
}

