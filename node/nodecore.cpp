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
	     QPluginLoader loader(pluginsDir.absoluteFilePath(fileName)); // should keep loader for on-the fly unload/reload
    	     QObject *object = loader.instance();
            if (object)
	    {
		if (HyPluginInterface *plugin=dynamic_cast<HyPluginInterface *>(object))
		{
//			QObject::connect(plugin, SIGNAL(signal_log(int, QString)), this, SLOT(slot_log(int, QString)));
		    if (plugin->implementation()==NotImplemented)
		    {
			slot_log(Warning, "This modules ["+plugin->name()+"] is not implemented yet. Please visit our github page and request this so it could be implemented earlier than in its schedule. This module unloads now!");
			loader.unload();
		    }
		    else
		    {
			slot_log(Info, plugin->name()+" loaded.");
			plugins.append(plugin);
		    }
		}
            } 
	    else 
	    {
		slot_log(Critical, "Load failed for file: "+fileName+" (reson: "+loader.errorString()+")");
	    }
        }
    }
    slot_log(Info, "Plugin loading ends");

    // We loaded what we could load. Now we define whether we run in console or GUI mode (needed for QApplication creation)
    for (int i=0;i<plugins.count();++i)
    {
	_requiredfeatures |= plugins.at(i)->requiredFeatures();
	qDebug() << i << " " << plugins.at(i)->name() << " " <<plugins.at(i)->requiredFeatures() << "  " << _requiredfeatures;
    }
}

void NodeCore::launchGUI()
{
    slot_log(Info, "GUI startup is requested by the plugins");
    basepanel=new BasePanel();
    basepanel->show();
}

void NodeCore::slot_log(int severity, QString logline)
{
    slot_log("", severity, logline);
}

void NodeCore::slot_log(QString source, int severity, QString logline)
{
    qDebug() << "["+QString::number(severity)+"] "+logline;
}
