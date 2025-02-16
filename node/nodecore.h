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
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include <QStateMachine>
#include <QState>
#include <QFinalState>

#include "buffer.h"
#include "common.h"
#include "hyplugin_interface.h"
#include "pluginslot.h"
#include "coreserver.h"
#include "unicore.h"
#include "hfs.h"
#include "hb_lookandfeel.h"

#ifdef PF_WASM
#include "emscripten.h"
#endif

class NodeCore : public QObject
{
Q_OBJECT

public:
    NodeCore(int argc, char* argv[], QObject *parent= nullptr);
    void launch();
    ~NodeCore();

    void loadPlugins();
   
    void connectPlugins();
    void initPlugins();
    void setGUIMode(int flag);
    int guiMode();

    QCoreApplication* mainapp;

public slots:
    void launchApplication();
    void log(int severity, QString logline, QString source="NODECORE");

    void sendDataPackToMesh(QString data) {}
    void sendDataPackToMesh(QDomNode node) {}

protected slots:
    void checkNodeBinary(const QString &str=QString());
    void restartNode();
    void connectHUDtoHFS();
    void activatePlugins();
    void loadQML();
    void fileChanged(const QString& str);

protected:
    QByteArray getBinaryFingerPrint(QString filename);

signals:
    void incomingDataPack(QDomNode node);
    void connectToRemoteServer(QString server, QString port);

private:
    void init();

private:
    int _argc;
    char** _argv;

    QList<PluginSlot *> pluginslots;
    QTimer checknodebin_timer;
    QByteArray node_binary_fingerprint;
    HFS* hfs;

    std::unique_ptr <QFileSystemWatcher> watcher;
    std::unique_ptr <QQmlApplicationEngine> qmlengine;
    std::unique_ptr <UniCore> unicore;
    std::unique_ptr <CoreServer> coreserver;

    //Buffers
    PackBuffer* ind_buffer;     // Coreserver->Unicore buffer
    PackBuffer* outd_buffer;    // Unicore->Coreserver buffer

    // NodeCore states
    QScopedPointer<QStateMachine> statemachine;     // State machine orchestrating states
    QScopedPointer<QState>        state_boot;       // The first thing
 
};

#endif