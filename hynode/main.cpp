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
    QCommandLineParser parser;
    parser.setApplicationDescription("Hyperborg node");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addOption(QCommandLineOption("f", QCoreApplication::translate("main", "Launch node in foreground, NOT in daemon mode")));
    parser.addOption(QCommandLineOption("c", QCoreApplication::translate("main", "Use configuration file instead of default hynode.imi")));
    parser.addOption(QCommandLineOption("t", QCoreApplication::translate("main", "Run instance parallel, not forcing existing instance to quit")));
    parser.addOption(QCommandLineOption("g", QCoreApplication::translate("main", "Force node to use GUI mode")));
    parser.addOption(QCommandLineOption("d", QCoreApplication::translate("main", "Use host to download configuration from")));
    parser.process(cmdline); // egg or chicken, McFly?

    // After parsing we should know what configuration file should be loaded

    // It is time to create the core for this node. Event loop is not yet running.
    // In this phase we preparing to load all the plugins enlisted in the configuration 
    // If there is any GUI required plugin to be used, we use GUI mode.
    // The default is the CORE mode
    // If CORE mode is set, it cannot be upgraded to GUI mode without reconfiguring and restart

    NodeCore *core = new NodeCore();
    core->loadPlugins();
    if (core->requiredFeatures() & GUISupport)
    {
	mainapp = new QGuiApplication(argc, argv);
    }
    else
    {
	mainapp = new QCoreApplication(argc, argv);
    }

    QCoreApplication::setApplicationName("hyperborg-node");
    QCoreApplication::setApplicationVersion("v0.56");

    return mainapp->exec();
}