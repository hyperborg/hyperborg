#include "nodecore.h"

NodeCore::NodeCore(int appmode, QObject *parent) : QObject(parent),
unicore_thread(NULL), unicore(NULL),
coreserver(NULL), coreserver_thread(NULL),
beacon(NULL), beacon_thread(NULL), _parser(NULL)
{
    _requiredfeatures = Standard;
    _appmode = appmode;
    _requestedMatrixId = 0;	// Matrix id we want to join by defaul
    settings = &HSettings::getInstance();
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
    qDebug() << i << " " << pluginslots.at(i)->pluginName() << " " <<pluginslots.at(i)->requiredFeatures() << "  " << _requiredfeatures;
    }
}

void NodeCore::launchGUI()
{
    init();
    slot_log(Info, "GUI startup is requested by the plugins");
    basepanel=new BasePanel();
    basepanel->show();

#ifdef USE_ADMINPANEL
    AdminPanel *adminpanel = new AdminPanel(basepanel);
    adminpanel->show();
#endif
    connectPlugins();
    initPlugins();
}


void NodeCore::launchConsole()
{
    qDebug() << "Launch console ...";
    init();
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

void NodeCore::setCMDParser(QCommandLineParser *parser)
{
    _parser=parser;
    if (!parser) return;

    // This is the main place where we are decising a lot of thing about how to behave
    // What we are deciding here is accessible for all plugins (in read only mode of course)


    if (_parser->isSet("config"))
    {
    qDebug() << "use different config: " << _parser->value("config");
    QString config=_parser->value("config");
    if (!config.isEmpty())
    {
        settings->useSettings(_parser->value(config));
    }
    }

    if (_parser->isSet("role"))
    {
    QString tval = _parser->value("ole").toUpper();
    if (tval=="MASTER" || tval=="SLAVE")
    {
        settings->setValue(Conf_NodeRole, tval);
    }
    }
    if (_parser->isSet("matrix"))
    {
    qDebug() << "MATRIX: " << _parser->value("matrix");
    settings->setValue(Conf_Matrix, _parser->value("matrix"));
    }
/*
    if (_parser->isSet("f"))
    {
    qDebug() << "Foreground is set";
    settings->setValue("NodeCore", "foreground", "true");
    }

    if (_parser->isSet("no-gui"))
    {
    qDebug() << "disable GUI mode";
    settings->setValue("NodeCore", "disable_gui", "true");
    }
*/
    if (_parser->isSet("remotehost"))
    {
    settings->setValue("NodeCore", "remote_host", _parser->value("remotehost"));
    qDebug() << "Turning beacon off, using remote host: " << _parser->value("remotehost");
    if (_parser->isSet("port"))
    {
        qDebug() << "Using different port for the connection: " << _parser->value("port");
        settings->setValue("NodeCore", "remote_host_port", _parser->value("port"));
    }
    }

    // One of the most important thing is in which matrix we want to be the part of
}

void NodeCore::init()
{
    unicore=new UniCore();
    unicore_thread = new QThread(this);
    unicore->moveToThread(unicore_thread);

    QString servername = "hyperborg-node";
    coreserver = new CoreServer(servername, QWebSocketServer::NonSecureMode, 33333); // for now. We add certs handling later
    coreserver_thread = new QThread();
    coreserver->moveToThread(coreserver_thread);

    beacon = new Beacon();
    beacon_thread=new QThread();
    beacon->moveToThread(beacon_thread);


    unicore_thread->start();
    beacon_thread->start();
    coreserver_thread->start();

    QMetaObject::invokeMethod(unicore, "init");
    QMetaObject::invokeMethod(beacon, "init");
    QMetaObject::invokeMethod(coreserver, "init");
}

// connectServices is where we query all loaded plugins what they provide or accept. This builds up the node's 
// featrue table that would be dispatched and collected by the master later on to make instruction deploy plannable

void NodeCore::connectServices()
{
    for (int i=0;i<pluginslots.count();i++)
    {
    }
}

