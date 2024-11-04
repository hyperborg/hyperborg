#include <bme688.h>
#include "../../node/job.h"

BME688::BME688(QObject* parent) : HPlugin(parent), HyPluginInterface()
{
}

BME688::~BME688()
{}


void BME688::loadConfiguration(QString str)
{
}
