#include "common.h"

#include <QCoreApplication>
#include <QGuiApplication>
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDebug>
#include <QProcess>

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
	qDebug() << "Version: " << HYPERBORG_VERSION << "  BUILD: " << HYPERBORG_BUILD_TIMESTAMP;
	qDebug() << " ===========================================================";

#if HTEST
	// Since beacon is not yet dispatcing versions and restarts, the current version
	// on remote devices should be checked semi-manually via hynode.log
	QFile f("hynode.log");
	if (f.open(QIODevice::Append))	
	{
		QTextStream stream(&f);
		QDateTime dt = QDateTime::currentDateTime();
		QString lline=QString("Started at %1\n").arg(dt.toString("yyyy.MM.dd hh:mm:ss.zzz"));
		stream << lline;
	}
#endif

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

//    parser->addOption({"f", "Launch node in foreground, NOT in daemon mode"});
	parser->addOption({{"c", "config"}, "Use configuration file instead of default hynode.imi", "config"});
	parser->addOption({{"g",  "gui"}, "Force node to use GUI mode" });
	parser->addOption({{"m", "matrix"}, "Define used matrix id - no automatic guess", "matrix"});
	parser->addOption({{"r", "remotehost"}, "Skip beaconing, connect directly to the given host", "remotehost"});
	parser->addOption({{"p", "port"}, "Use this port for remote connection (use with -r), default is 33333"});
	parser->addOption({{"t", "type"}, "Set node type: master, slave", "type"});

	QCoreApplication *pa=new QCoreApplication(argc, argv);
	parser->process(cmdline);

	// After parsing we should know what configuration file should be loaded

	// It is time to create the core for this node. Event loop is not yet running.
	// In this phase we preparing to load all the plugins enlisted in the configuration
	// If there is any GUI required plugin to be used, we use GUI mode.
	// The default is the CORE mode
	// If CORE mode is set, it cannot be upgraded to GUI mode without reconfiguring and restart

	NodeCore *core = new NodeCore();
	// The command line parsing is done before loading any plugins, since ex. if the no gui parameter is set
	// we should not load plugins requesting GUI subsystem

	core->setCMDParser(parser);
	core->loadPlugins();
	int force_gui=false;
	if (core->forcedGUIMode()) force_gui = true;
#ifdef WIN32
	force_gui = true;
#endif
#ifdef WASM
	force_gui=true;
#endif

	if (force_gui || (core->requiredFeatures() & GUISupport))
	{
		delete(pa); //Kind of upgrading application, so we need to drop core (is there a better way?)
		qDebug() << "-- GUI APPLICATION STARTUP --";
		mainapp = new QApplication(argc, argv);
		QMetaObject::invokeMethod(core, "launchGUI", Qt::QueuedConnection);
	}
	else
	{
		qDebug() << "-- CONSOLE APPLICATION STARTUP --";
		mainapp = pa;
		QMetaObject::invokeMethod(core, "launchConsole", Qt::QueuedConnection);
	}

	QCoreApplication::setApplicationName("hyperborg-node");
	QCoreApplication::setApplicationVersion("v0.56");

	int rc = mainapp->exec();
	if (rc==NODE_RESTART_CODE)
	{
	    QProcess *proc = new QProcess();
	    QStringList args = qApp->arguments();
	    proc->setProgram(args.at(0));
	    args.removeFirst();
	    proc->setArguments(args);
	    proc->startDetached();
	}

	return rc;
}

