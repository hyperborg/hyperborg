#ifndef CORESERVER_H
#define CORESERVER_H

#include <QObject>
#include <QWebSocketServer>
#include <QSslError>
#include <QSslConfiguration>
#include <QSslKey>
#include <QProcess>
#include <QHash>
#include <QHashIterator>

#include <QString>
#include <QByteArray>
#include <QWebSocket>
#include <QThread>
#if !defined(PF_WASM) && !defined(PF_ANDROID)
#include <QSslPreSharedKeyAuthenticator>
#endif

#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QTimer>
#include <QFile>

#include "common.h"
#include "common_network.h"
#include "buffer.h"
#include "hfs.h"
#include "datapack.h"
#include "job.h"

class Executor;

class CoreServer : public QObject
{
    friend class Executor;

Q_OBJECT
public:
    CoreServer(HFS *hfs, QObject *parent=nullptr);
    ~CoreServer();

    void setInboundBuffer(PackBuffer* b) { inbound_buffer = b; }
    void setOutbountBuffer(PackBuffer* b) { outbound_buffer = b; }

signals:
    void incomingData(DataPack* pack);

public slots:
    void init();
    void newData();
    void connectToRemoteServer(const QString &remoteserver, const QString &port);
    void nodeRoleChanged(Job *job);

protected slots:
    QVariant epochChanged(Job* job);

private slots:
    void slot_acceptError(QAbstractSocket::SocketError socketError);
    void slot_closed();
    void slot_newConnection();

    void slot_serverError(QWebSocketProtocol::CloseCode closeCode);
    void slot_processTextMessage(const QString &message);
    void slot_processBinaryMessage(const QByteArray &message);
    void slot_socketConnected();
    void slot_socketDisconnected();
    void slot_error(QAbstractSocket::SocketError error);
    void slot_stateChanged(QAbstractSocket::SocketState state);
    void slot_sslErrors(const QList<QSslError>& lst);

    void slot_originAuthenticationRequired(QWebSocketCorsAuthenticator*);
#if !defined(PF_WASM) && !defined(PF_ANDROID)
    void slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator*);
#endif
    void slot_peerVerifyError(const QSslError&);
    void slot_tryReconnect();
    void slot_pingSockets();
    void slot_sendPacksOut();

private:
    void log(int severity, const QString &line);

private:
    QScopedPointer<QWebSocketServer> serversocket;
    QHash<int, NodeRegistry*> sockets;
    QHash<int, int> devid_socket;
    int idsrc;
    int mastersocket_id;            // Socket id used by the master (only relevant in slave mode)
    PackBuffer* inbound_buffer;     // DataPacks coming from the network
    PackBuffer* outbound_buffer;    // DataPack are waiting to be sent

    QString _remote_host;           // URL of where the application should connect
    QString _remote_port;

    QTimer* testtimer;
    QTimer* rc_timer;              // Socket reconnect timer
    int noderole_master;           // Puffering noderole, should not call HFS for all packets
    HFS* hfs;
    QString device_name;
};

#endif
