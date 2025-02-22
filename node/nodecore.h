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
    Q_PROPERTY(QString state READ state WRITE setState NOTIFY stateChanged);

public:
    NodeCore(int argc, char* argv[], QObject *parent= nullptr);
    ~NodeCore();

    void setGUIMode(int flag);
    int guiMode();

    QCoreApplication* mainapp;

    QString state();

public slots:
    void log(int severity, QString logline, QString source="NODECORE");
    void setState(QString st);

protected slots:
    void checkNodeBinary(const QString &str=QString());
    void restartNode();
//    void fileChanged(const QString& str);

protected:
    QByteArray getBinaryFingerPrint(QString filename);
    void createStateMachine();
    void createApp();

signals:
    void incomingDataPack(QDomNode node);
    void connectToRemoteServer(QString server, QString port);
    void stateChanged();

private:
    int _argc;
    char** _argv;

    QHash<QString, PluginSlot *> pluginslots;
    QByteArray node_binary_fingerprint;
    HFS* hfs;

    std::unique_ptr <QFileSystemWatcher> watcher;
    std::unique_ptr <QQmlApplicationEngine> qmlengine;
    std::unique_ptr <UniCore> unicore;
    std::unique_ptr <CoreServer> coreserver;

    //Buffers
    QSharedPointer<PackBuffer> ind_buffer;     // Coreserver->Unicore buffer
    QSharedPointer<PackBuffer> outd_buffer;    // Unicore->Coreserver buffer

    // NodeCore states
    QScopedPointer<QStateMachine> statemachine;   // State machine orchestrating states
    QScopedPointer<QState>        state_start;    // The first state of NodeCore. Only NodeCore exists, no HFS or any other structure
                                                  // From this state it builds HFS, queues, UniCore 
    QScopedPointer<QState>        state_init;     // Entering: creating HFS, Unicore and queues if they are not existing
                                                  // Leaving: HFS, Unicore and queues are stopped and destroyed
    QScopedPointer<QState>        state_launch;   // State in which QApplication or QCoreApplication is set up
    QScopedPointer<QState>        state_qml;      // Load/recreate QML display if necessary
    QScopedPointer<QState>        state_split;    // In this state the node is disconnected from the mesh. It tries to connect/reconnect
                                                  // to the mesh. This state is left when reconnection is successful, or due to timeout
                                                  // the node can start up as a master node. 
    QScopedPointer<QState>        state_sync;     // In this state, the node is already connected to the mesh, but needs to sync its
                                                  // internal HFS (including the active Flower flows)
    QScopedPointer<QState>        state_plugins;  // In this state the node loads/reloads plugins depending on their settings. 
                                                  // Here one should be cautios about changing only plugins having modified settings
    QScopedPointer<QState>        state_online;   // In this state the node if fully functional and in sync
    QScopedPointer<QState>        state_standby;  // The node is connected to the mesh, but does not execute any flow (used for parameter/
                                                  // flow update
    QScopedPointer<QState>        state_fork;     // Entering into this state means that application needs to be forked due to binary update

    QString prevstate_str;
    QElapsedTimer elapsed;
    QString _state;

private slots:
    void stateStartEntered();
    void stateStartExited();
    void stateInitEntered();
    void stateInitExited();
    void stateLaunchEntered();
    void stateLaunchExited();
    void stateQMLEntered();
    void stateQMLExited();
    void stateSplitEntered();
    void stateSplitExited();
    void stateSyncEntered();
    void stateSyncExited();
    void statePluginsEntered();
    void statePluginsExited();
    void stateOnlineEntered();
    void stateOnlineExited();
    void stateStandByEntered();
    void stateStandByExited();
    void stateForkEntered();
    void stateForkExited();

signals:    // state related signals
    void startFinished();
    void initFinished();
    void launchFinished();
    void qmlFinished();
    void splitFinished();
    void syncFinished();
    void pluginsFinished();
    void standByFinished();
    void forkFinished();


};

#endif