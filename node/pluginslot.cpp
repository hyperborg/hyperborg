#include "pluginslot.h"

PluginSlot::PluginSlot(QObject *parent) : QObject(parent), pluginloader(NULL), object(NULL)
{
}

PluginSlot::~PluginSlot()
{}


