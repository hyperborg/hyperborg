#include <bme688.h>
#include "../../node/job.h"

BME688::BME688(QObject* parent) : HyPluginInterface(), HDevice(parent)
{
}

BME688::~BME688()
{}


void BME688::loadConfiguration(QString str)
{
}
