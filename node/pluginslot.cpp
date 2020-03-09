#include "pluginslot.h"

PluginSlot::PluginSlot(QObject *parent) : QObject(parent), pluginloader(NULL), instance(NULL), _parent(parent)
{
    wthread=new QThread(this);
    pluginloader = new QPluginLoader(this);
}

PluginSlot::~PluginSlot()
{}

bool PluginSlot::initializePlugin(QString name)
{
    pluginloader->setFileName(name);
    if (pluginloader->load())
    {
	instance = pluginloader->instance();
        if (instance)
	{
	    if (HyPluginInterface *plugin=dynamic_cast<HyPluginInterface *>(instance))
	    {
		if (plugin->implementation()==NotImplemented)
		{
		    slot_log(Warning, "This modules ["+plugin->name()+"] is not implemented yet. Please visit our github page and request this so it could be implemented earlier than in its schedule. This module unloads now!");
		    pluginloader->unload();
		    instance=NULL;
		    return false;
		}
		else
		{
		    slot_log(Info, plugin->name()+" loaded.");
		    instance->moveToThread(wthread);
		}
	    }
        }
	else
	{
	    slot_log(Critical, "Load failed for file: "+name+" (reason: "+pluginloader->errorString()+")");
	    return false;
	}
    }
    return true;
}

int PluginSlot::requiredFeatures()
{
    int retint = 0;
    if (!instance) return retint;
    if (HyPluginInterface *plugin=dynamic_cast<HyPluginInterface *>(instance))
    {
	retint = plugin->requiredFeatures();
    }
    return retint;
}

void PluginSlot::slot_log(int severity, QString logline)
{
    qDebug() << "[" << severity << "] " << logline;
}

bool PluginSlot::initPlugin()
{
    qDebug() << "initPlugin: " << instance;
    if (!instance) return false;
    QMetaObject::invokeMethod(instance, "init", Qt::QueuedConnection);
    wthread->start();
    qDebug() << "initPlugin ends";
    return true;
}

bool PluginSlot::connectPlugin()
{
    if (!instance) return false;
    if (HyPluginInterface *hif = dynamic_cast<HyPluginInterface *>(instance))
    {
	QObject *obj = hif->getObject();
	if(!obj)
	{
	    slot_log(Warning, "Plugin ["+hif->name()+"] does not provide QObject interface. It is not used anymore!");
	}
	else
	{
	    bool c = QObject::connect(obj, SIGNAL(signal_log(QString, int, QString)), _parent, SLOT(slot_log(QString, int, QString)), Qt::QueuedConnection);
	    if (!c)
	    {
		    //?? slot_log(Warning, "Plugin ["+hif->name()+"] does not provide logging!");
		    return false;
	    }
	}
    }
    return true;
}
