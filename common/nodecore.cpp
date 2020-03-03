#include "nodecore.h"

NodeCore::NodeCore(int appmode, QObject *parent) : QObject(parent)
{
    _requiredfeatures = NoFeature;
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
    qDebug() << "-- loadPlugins --";
    QPluginLoader loader("almafa");
    QDir pluginsDir("plugins");
    const auto entryList = pluginsDir.entryList(QDir::Files);
    for (const QString &fileName : entryList)
    {
	qDebug() << "Trying: " << fileName;
	 QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
         QObject *object = loader.instance();
         if (object)
	 {
	    qDebug() << "MAGICK: Could load plugin";
	    if (HyPluginInterface *plugin=dynamic_cast<HyPluginInterface *>(object))
	    {
//		QObject::connect(plugin, SIGNAL(signal_log(int, QString)), this, SLOT(slot_log(int, QString)));
		plugins.append(plugin);
	    }
          } else qDebug()  << "no object";
      }
    qDebug() << "--loadPlugins ends";
}

void NodeCore::slot_log(QString source, int severity, QString logline)
{
}
