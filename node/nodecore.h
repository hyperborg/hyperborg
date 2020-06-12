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
#include <QCryptographicHash>
#include <QDateTime>

#include "common.h"
#include "nodecore_inc.h"
#include "hyplugin.h"
#include "beacon.h"
#include "basepanel.h"
#include "pluginslot.h"
#include "coreserver.h"
#include "hsettings.h"
#include "unicore.h"
#include "slotter.h"

#ifdef WASM
#include "emscripten.h"
#endif

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

    void log(int severity, QString logline);
    void slot_log(QString source, int severity, QString logline);
    void slot_log(int severity, QString logline);

    void sendDataBlockToMesh(QString data) {}
    void sendDataBlockToMesh(QDomNode node) {}

protected slots:
    void checkNodeBinary();
    void restartNode();
    void mastertimer_timeout();
    void connect(QString id, QString ip, int port);
    void matrixEcho(NodeCoreInfo info);
    void joinNetwork(NodeCoreInfo info);

protected:
    QByteArray getBinaryFingerPrint(QString filename);
	void launchApplication();

signals:
    void incomingDataBlock(QDomNode node);
    void logLine(QString str);
    void setRole(NodeCoreInfo info);
    void setupCoreServer(NodeCoreInfo info);
    void connectToRemoteServer(QString server, QString port);

private:
    void init();
    void initNetworking();

private:
    HSettings *settings;
    QCommandLineParser *_parser;
    QList<PluginSlot *> pluginslots;
    UniCore *unicore;
    Slotter* slotter;
    CoreServer *coreserver;
    QThread* coreserver_thread;
    Beacon *beacon;
    QThread* beacon_thread;
    QTimer beacon_timer;
    QTimer checknodebin_timer;
    int _requiredfeatures;
    int _appmode;
    int _requestedMatrixId;
    QByteArray node_binary_fingerprint;
	bool _guimode;
    QTimer* mastertimer;
    QVector<QString> logpuffer;
    NodeCoreInfo nodeinfo;
    QWebSocket* wsocket;

    //BUffers 
    DataBuffer* ind_buffer;     // Coreserver->Unicore buffer
    DataBuffer* outd_buffer;    // Unicore->Coreserver buffer
    PackBuffer* inp_buffer;     // Unicore->Slotter buffer
    PackBuffer* outp_buffer;    // Slotter->Unicore buffer

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