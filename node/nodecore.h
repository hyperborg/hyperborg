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
#include <QByteArray>
#include <QByteArrayView>
#include <QCryptographicHash>
#include <QDateTime>
#include <QFileSystemWatcher>
#include <QFileInfo>

#include "common.h"
#include "nodecore_inc.h"
#include "hyplugin.h"
#include "pluginslot.h"
#include "coreserver.h"
#include "unicore.h"
#include "slotter.h"
#include "hfs.h"

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
    void setGUIMode(int flag);
    int guiMode();

public slots:
    void launchGUI();
    void launchConsole();

    void log(int severity, QString logline, QString source="NODECORE");

    void sendDataPackToMesh(QString data) {}
    void sendDataPackToMesh(QDomNode node) {}

protected slots:
    void checkNodeBinary(const QString &str);
    void checkNodeBinary();
    void restartNode();
    void connect(QString id, QString ip, int port);

protected:
    QByteArray getBinaryFingerPrint(QString filename);
    void launchApplication();

signals:
    void incomingDataPack(QDomNode node);
    void connectToRemoteServer(QString server, QString port);

private:
    void init();

private:
    QCommandLineParser *_parser;
    QList<PluginSlot *> pluginslots;
    HFS* hfs;
    UniCore *unicore;
    Slotter* slotter;
    CoreServer *coreserver;
    QThread* coreserver_thread;
    QTimer checknodebin_timer;
    int _requiredfeatures;
    int _appmode;
    int _requestedMatrixId;
    QByteArray node_binary_fingerprint;
    QFileSystemWatcher* watcher;

    bool _guimode;
    QTimer* mastertimer;
    bool logpuffer_used;
    QStringList logpuffer;
    QWebSocket* wsocket;

    //Buffers
    PackBuffer* ind_buffer;     // Coreserver->Unicore buffer
    PackBuffer* outd_buffer;    // Unicore->Coreserver buffer
    PackBuffer* inp_buffer;     // Unicore->Slotter buffer
    PackBuffer* outp_buffer;    // Slotter->Unicore buffer
};

#endif