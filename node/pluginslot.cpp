#include "pluginslot.h"

PluginSlot::PluginSlot(HFS *_hfs, QObject *parent) : QObject(parent), pluginloader(nullptr), _instance(nullptr), _parent(parent), _interface(nullptr)
{
    wthread=new QThread(this);
    pluginloader = new QPluginLoader(this);
    hfs = _hfs;
}

PluginSlot::~PluginSlot()
{}

bool PluginSlot::initializePlugin(QString filename)
{
    pluginloader->setFileName(filename);
    if (pluginloader->load())
    {
        _instance = pluginloader->instance();
        if (_instance)
        {
            if ((_interface=qobject_cast<HyPluginInterface *>(_instance)))
            {
                if (_interface->implementation()==NotImplemented)
                {
                    slot_log(Warning, "This module ["+_interface->name()+"] is not implemented yet. Please visit our github page and request this so it could be implemented earlier than in its schedule. This module unloads now!");
                    pluginloader->unload();
                    _instance= nullptr;
                    _interface= nullptr;
                    return false;
                }
                else
                {
                    slot_log(Info, _interface->name()+" loaded.");
                    if (_plugin = dynamic_cast<HPlugin*>(_interface->getObject()))
                    {
                        _plugin->setHFS(hfs);
                    }
                    _name = _interface->name();
                }
            }
        else
        {
            slot_log(Critical, "HyPluginInterface cannot be casted from plugin: "+ filename);
            return false;
        }
        }
    else    // if (_instance)
    {
        slot_log(Critical, "Load failed for file: "+filename+" (reason: "+pluginloader->errorString()+")");
        return false;
    }
    }
    else
    {
        slot_log(Critical, "Load failed for file: "+filename+" (reason: "+pluginloader->errorString()+")");
        return false;
    }
    return true;
}

int PluginSlot::requiredFeatures()
{
    int retint = 0;
    if (!_instance) return retint;
    if (!_interface) return retint;
    return _interface->requiredFeatures();
}

void PluginSlot::slot_log(int severity, QString logline, QString source)
{
    emit logLine(severity, logline, source);
}

bool PluginSlot::initPlugin()
{
    if (!_instance) return false;
    qDebug() << "initPlugin: " << _instance << " PluginSlot thread: " << QThread::currentThread();
    QString configstr = "";
    QMetaObject::invokeMethod(_instance, "loadConfiguration", Qt::DirectConnection, Q_ARG(QString, configstr));
    _instance->moveToThread(wthread);
    wthread->start();
    qDebug() << "initPlugin ends";
    return true;
}


void PluginSlot::pluginStart()
{
    /*
    if (_instance && wthread)
    {
        _instance->moveToThread(wthread);
        wthread->start();
    }
    */
}

bool PluginSlot::connectPlugin()
{
    if (!_instance) return false;
    if (!_interface) return false;
    QObject *obj = _interface->getObject();
    if(!obj)
    {
        slot_log(Warning, "Plugin ["+_interface->name()+"] does not provide QObject interface. It is not used anymore!");
    }
    else
    {
        bool c = QObject::connect(obj, SIGNAL(signal_log(int, QString, QString)), hfs, SLOT(log(int, QString, QString)), Qt::QueuedConnection);
        if (!c)
        {
            slot_log(Warning, "Plugin ["+_interface->name()+"] does not provide logging!");
            return false;
        }
    }
    return true;
}

bool PluginSlot::setConfiguration(QJsonObject& json)
{
    return false;
}

