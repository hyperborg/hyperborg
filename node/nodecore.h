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
#include <common.h>

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
    QList<HyPluginInterface *> plugins;
    int _requiredfeatures;
    int _appmode;

//  GUI related objects
    BasePanel *basepanel;


/* TESTING FUNCIONTS - REMOVED ON FIRST RELEASE*/
    QStringList activePlugins()
    {
	QStringList lst;
	lst << "libtestplugin.so";
	lst << "libadminpanel.so";
	lst << "libhyi2c.so";
	lst << "libonewire.so";
	lst << "libapcaccess.so";
	return lst;
    }
};

#endif