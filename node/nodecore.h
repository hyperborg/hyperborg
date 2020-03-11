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

#include "nodecore_inc.h"
#include "hyplugin.h"
#include "beacon.h"
#include "basepanel.h"
#include <pluginslot.h>
#include "coreserver.h"

#include <common.h>
#include <unicore.h>

class NodeCore : public QObject
{
Q_OBJECT

public:
    NodeCore(int appmode=Standard, QObject *parent=NULL);
    void launch();
    ~NodeCore();

    void loadPlugins();
    int requiredFeatures() { return _requiredfeatures; }
    int appMode() { return _appmode; }

    void connectPlugins();
    void initPlugins();

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
//    QList<HyPluginInterface *> plugins;
    QList<PluginSlot *> pluginslots;
    UniCore *unicore;
    QThread *unicore_thread;
    CoreServer *coreserver;
    QThread *coreserver_thread;	// comm should be in thread due to webassembly constraints
    int _requiredfeatures;
    int _appmode;

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