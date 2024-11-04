#include <bme688_bsec.h>
#include "../../node/job.h"

BME688_BSEC::BME688_BSEC(QObject* parent) : HPlugin(parent), HyPluginInterface()
{
}

BME688_BSEC::~BME688_BSEC()
{}


void BME688_BSEC::loadConfiguration(QString str)
{
}
