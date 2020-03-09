#include "nodecore.h"

NodeCore::NodeCore(int appmode, QObject *parent) : QObject(parent)
{
    _requiredfeatures = Standard;
    _appmode = appmode;
}

NodeCore::~NodeCore()
{
}

void NodeCore::launch()
{
}

void NodeCore::loadPlugins()
{
    // Loading all plugins rom the 'plugins' subdirectory. Only the ones matching activePlugins() are actually tried
    slot_log(Info, "Plugin load started");
    QStringList namefilters;
    namefilters << "*.so" << "*.dll";
    QDir pluginsDir("plugins");
    const auto entryList = pluginsDir.entryList(namefilters, QDir::Files);
    for (const QString &fileName : entryList)
    {
	if (activePlugins().contains(fileName))
	{
	    PluginSlot *pluginslot = new PluginSlot(this);
	    if (pluginslot->initializePlugin(pluginsDir.absoluteFilePath(fileName)))
	    {
		pluginslots.append(pluginslot);
	    }
	    else
	    {
		pluginslot->deleteLater();
	    }
        }
    }
    slot_log(Info, "Plugin loading ends");

    // We loaded what we could load. Now we define whether we run in console or GUI mode (needed for QApplication creation)
    for (int i=0;i<pluginslots.count();++i)
    {
	_requiredfeatures |= pluginslots.at(i)->requiredFeatures();
	qDebug() << i << " " << pluginslots.at(i)->name() << " " <<pluginslots.at(i)->requiredFeatures() << "  " << _requiredfeatures;
    }
}

void NodeCore::launchGUI()
{
    slot_log(Info, "GUI startup is requested by the plugins");
    basepanel=new BasePanel();
    basepanel->show();

#ifdef USE_ADMINPANEL
    AdminPanel *adminpanel = new AdminPanel(basepanel);
    adminpanel->show();
#endif

    connectPlugins();
}

void NodeCore::launchConsole()
{
    qDebug() << "Launch console ...";
    connectPlugins();
    initPlugins();
}

void NodeCore::connectPlugins()
{
    for (int i=0; i<pluginslots.count(); i++)
    {
	qDebug() << "ConnectPlugin " << i;
	pluginslots.at(i)->connectPlugin();
    }
}

void NodeCore::initPlugins()
{
    for (int i=0; i<pluginslots.count(); i++)
    {
	qDebug() << "initPlugin " << i;
	pluginslots.at(i)->initPlugin();
    }
}

void NodeCore::slot_log(int severity, QString logline)
{
    slot_log("", severity, logline);
}

void NodeCore::slot_log(QString source, int severity, QString logline)
{
    qDebug() << "["+QString::number(severity)+"] "+logline;
}
