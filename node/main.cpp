#include "common.h"

#include <QCoreApplication>
#include <QGuiApplication>
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDebug>
#include <QProcess>
#include <memory>

#include "nodecore.h"

/* ============ HANDLING SIGNALS FROM OUTSIDE ============ */

void SigIntHandler()
{
    qDebug()<<"Ctrl-C received.  Quitting.";
    qApp->quit();
}

void SigHupHandler()
{
    // Handle SIGHUP if necessary
}

#if defined(Q_OS_UNIX) || defined(Q_OS_LINUX) || defined(Q_OS_QNX)
  #include <signal.h>

  void unix_handler(int s)
  {
    switch(s)
    {
        case SIGINT:    SigIntHandler(); break;
        case SIGHUP:    SigHupHandler(); break;
    }
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

/* ============ APPLICATION MAIN ENTRY POINT ============ */

int main(int argc, char *argv[])
{
    // setup event handlers
    #if defined(Q_OS_UNIX) || defined(Q_OS_LINUX) || defined(Q_OS_QNX)
        signal(SIGINT, &unix_handler);
    #elif defined(Q_OS_WIN32)
        SetConsoleCtrlHandler((PHANDLER_ROUTINE)WinHandler, TRUE);
    #endif

    NodeCore *core = new NodeCore(argc, argv);
    int rc = core->mainapp->exec();

#ifndef PF_WASM
    // Should be controlled by configuration
    bool can_be_rebooted = true;
    if (can_be_rebooted && rc==NODE_RESTART_CODE)
    {
        QProcess *proc = new QProcess();
        QStringList args = qApp->arguments();
        proc->setProgram(args.at(0));
        args.removeFirst();
        proc->setArguments(args);
        proc->startDetached();
    }
#endif
    return rc;
}

