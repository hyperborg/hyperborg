#include <QCoreApplication>
#include <QGuiApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDebug>

#include <nodecore.h>

void SigIntHandler()
{
    qDebug()<<"Ctrl-C received.  Quitting.";
    qApp->quit();
}

void SigHupHandler()
{
}

#if defined(Q_OS_UNIX) || defined(Q_OS_LINUX) || defined(Q_OS_QNX)
  #include <signal.h>

  void unix_handler(int s)
  {
	switch(s)
    {
	case SIGINT:	SigIntHandler(); break;
	case SIGHUP:	SigHupHandler(); break;

    }

    if (s==SIGINT)
        SigIntHandler();
  }

#elif defined(Q_OS_WIN32)
  #include <windows.h>

  BOOL WINAPI WinHandler(DWORD CEvent)
  {
    switch (CEvent)
    {
    case CTRL_C_EVENT:
        SigIntHandler();
        break;
    }
    return TRUE;
  }
#endif

int main(int argc, char *argv[])
{
    // Save params into a qstring
    QStringList cmdline;
    for (int i=0; i<argc; ++i)
    {
	cmdline << QString::fromLocal8Bit(argv[i]);
    }

    QCoreApplication *mainapp=NULL;
    qDebug() << " =================== HYPERBORG NODE ========================";
    qDebug() << "**";
    qDebug() << " ===========================================================";

    // setup event handlers
    #if defined(Q_OS_UNIX) || defined(Q_OS_LINUX) || defined(Q_OS_QNX)
        signal(SIGINT, &unix_handler);
    #elif defined(Q_OS_WIN32)
        SetConsoleCtrlHandler((PHANDLER_ROUTINE)WinHandler, TRUE);
    #endif

    // parse command line arguments if there is any
    QCommandLineParser *parser=new QCommandLineParser();
    parser->setApplicationDescription("Hyperborg node");
    parser->addHelpOption();
    parser->addVersionOption();

    parser->addOption({"f", "Launch node in foreground, NOT in daemon mode"});
    parser->addOption({{"c", "config"}, "Use configuration file instead of default hynode.imi", "config"});
    parser->addOption({"t", "Run instance parallel, not forcing existing instance to quit"});
    parser->addOption({"g", "Force node to use GUI mode"});
    parser->addOption({"d", "Use host to download configuration from"});
    parser->addOption({{"m", "matrix"}, "Define used matrix id - no automatic guess", "matrix"});
    parser->addOption({{"r", "remotehost"}, "Skip beaconing, connect directly to the given host", "remotehost"});
    parser->addOption({{"p", "port"}, "Use this port for remote connection (use with -r), default is 33333"});
    parser->addOption({{"q", "quiet"}, "Suppress verbose information", "quiet"});
    qDebug() << "Process-1";
    QCoreApplication *pa=new QCoreApplication(argc, argv);
    parser->process(cmdline);
    delete(pa);
    qDebug() << "Process-2";

    // After parsing we should know what configuration file should be loaded

    // It is time to create the core for this node. Event loop is not yet running.
    // In this phase we preparing to load all the plugins enlisted in the configuration
    // If there is any GUI required plugin to be used, we use GUI mode.
    // The default is the CORE mode
    // If CORE mode is set, it cannot be upgraded to GUI mode without reconfiguring and restart

    NodeCore *core = new NodeCore();
    core->loadPlugins();
    int force_gui=false;
#ifdef WASM
    force_gui=true;
#endif
    if (force_gui || (core->requiredFeatures() & GUISupport))
    {
	qDebug() << "-- GUI APPLICATION STARTUP --";
	mainapp = new QApplication(argc, argv);
	core->setCMDParser(parser);
	QMetaObject::invokeMethod(core, "launchGUI", Qt::QueuedConnection);
    }
    else
    {
	qDebug() << "-- CONSOLE APPLICATION STARTUP --";
	mainapp = new QCoreApplication(argc, argv);
	core->setCMDParser(parser);
	QMetaObject::invokeMethod(core, "launchConsole", Qt::QueuedConnection);
    }

    QCoreApplication::setApplicationName("hyperborg-node");
    QCoreApplication::setApplicationVersion("v0.56");

    return mainapp->exec();
}

