#include "slotter.h"

Slotter::Slotter(QObject* parent) : QThread(parent)
{
    waitcondition = new QWaitCondition();
    slotter_mutex = new QMutex();
}

Slotter::~Slotter()
{
}


void Slotter::log(int severity, QString line)
{
    emit logLine(severity, line, "SLOTTER");
}

void Slotter::run()
{
    forever
    {
        slotter_mutex->lock();
        waitcondition->wait(slotter_mutex, 2000);
        int pp = 1;
        while (pp)
        {
            pp = 0;
            pp += processPackFromUniCore();
        }
        slotter_mutex->unlock();
    }
}


int Slotter::processPackFromUniCore()
{
    DataPack* pack = inbound_buffer->takeFirst();
    if (!pack) return 0;
    QString tentid = pack->entityId();	// target entity id
/* -- OBSOLETE CODE
    if (Entity *ent = getEntity(tentid))
    {
        ent->changeValues(pack->attributes);
        return 1;
    }
*/
    delete(pack);	// Your story ended here :D
    return 0;
}

void Slotter::init()
{
    log(0, "Slotter init");
}

void Slotter::activatePlugins()
{
    log(0, "Slotter activatePlugins");
    for (int i=0;i<pluginslots.count();i++)
    {
        PluginSlot *act = pluginslots.at(i);
        if (HyPluginInterface *iface = act->pluginInterface())
        {
            log(0, " ------------------------ PLUGIN -----------------");
            log(0, "  Name: " + iface->name());
            log(0, "  Desc: " + iface->description());
            log(0, "  Ver : " + iface->version());
            log(0, "  Auth: " + iface->author());
            QMetaObject::invokeMethod(iface->getObject(), "setup");
            iface->dumpConfigurationToFile();
        }
        else log(0, "NO IFACE found");
    }
}

void Slotter::loadConfiguration(QJsonObject& obj)
{
    log(0, "-- SETTING CONFIGURATION FOR PLUGINS -- ");
    for (int i = 0; i < pluginslots.count(); i++)
    {
        PluginSlot* act = pluginslots.at(i);
        if (HyPluginInterface* iface = act->pluginInterface())
        {
            QJsonValue val = obj[iface->name()];
            if (val.isObject())
            {
                QJsonObject loadobject = val.toObject();
                iface->loadConfiguration(loadobject);
            }
        }
    }
}

void Slotter::saveConfiguration(QJsonObject& obj)
{
    for (int i = 0; i < pluginslots.count(); i++)
    {
        PluginSlot* act = pluginslots.at(i);
        if (HyPluginInterface* iface = act->pluginInterface())
        {
            QJsonObject pobj;
            iface->saveConfiguration(pobj);
            obj[iface->name()] = pobj;
        }
    }
}
