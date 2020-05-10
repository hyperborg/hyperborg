#ifndef NODECORE_H
#define NODECORE_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QPluginLoader>
#include <QDir>
#include <QDomNode>
#include <QCommandLineParser>
#include <QHash>
#include <QState>
#include <QStateMachine>

#include "nodecore_inc.h"
#include "hyplugin.h"
#include "beacon.h"
#include "basepanel.h"
#include <pluginslot.h>
#include "coreserver.h"
#include "hsettings.h"

#include <common.h>
#include <unicore.h>

class NodeCore : public QObject
{
Q_OBJECT

public:
    NodeCore(int appmode=Standard, QObject *parent=NULL);
    void launch();
    ~NodeCore();

    void setCMDParser(QCommandLineParser *parser);
    void loadPlugins();
    int requiredFeatures() { return _requiredfeatures; }
    int appMode() { return _appmode; }

    void connectPlugins();
    void initPlugins();
    void connectServices();

public slots:
    void launchGUI();
    void launchConsole();

    void slot_log(QString source, int severity, QString logline);
    void slot_log(int severity, QString logline);

    void sendDataBlockToMesh(QString data) {}
    void sendDataBlockToMesh(QDomNode node) {}

signals:
    void incomingDataBlock(QDomNode node);

private:
    void init();
    void initBeacon();

private:
    HSettings *settings;
    QCommandLineParser *_parser;
    QList<PluginSlot *> pluginslots;
    UniCore *unicore;
    QThread *unicore_thread;
    CoreServer *coreserver;
    QThread *coreserver_thread;	// comm should be in thread due to webassembly constraints
    Beacon *beacon;
    QThread *beacon_thread;
    QTimer beacon_timer;
    int _requiredfeatures;
    int _appmode;
    int _requestedMatrixId;

//  GUI related objects
    BasePanel *basepanel;


/* TESTING FUNCIONTS - REMOVED ON FIRST RELEASE*/
    QStringList activePlugins()
    {
	QStringList lst;

	QFile f("test_modules.imi");
	if (f.open(QIODevice::ReadOnly))
	{
	    QString wstr = QString(f.readAll());
	    lst = wstr.split("\n");
	}
	return lst;
    }
};

#endif