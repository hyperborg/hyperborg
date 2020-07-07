#ifndef CORESERVER_H
#define CORESERVER_H

#include <QObject>
#include <QWebSocketServer>
#include <QSslError>
#include <QSslConfiguration>
#include <QSslKey>

#include <QWebSocketCorsAuthenticator>
#include <QSslPreSharedKeyAuthenticator>
#include <QHash>
#include <QHashIterator>

#include <QString>
#include <QByteArray>
#include <QWebSocket>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QTimer>
#include <QFile>

#include "common.h"
#include "buffer.h"
#include "hsettings.h"

class CoreServer : public QWebSocketServer
{
Q_OBJECT
public:
    CoreServer(QString servername, QWebSocketServer::SslMode securemode, int port, QObject *parent=nullptr);
    ~CoreServer();

    void setInboundBuffer(DataBuffer* b) { inbound_buffer = b; }
    void setOutbountBuffer(DataBuffer* b) { outbound_buffer = b; }

public slots:
    void init();
    void setup(NodeCoreInfo info);
    void setRole(NodeCoreInfo info);
    void newData();
    void connectToRemoteServer(QString remoteserver, QString port);

signals:
    void logLine(int severity, QString line);
    void incomingData(DataBlock* datablock);

private slots:
    void slot_acceptError(QAbstractSocket::SocketError socketError);
    void slot_closed();
    void slot_newConnection();
    void slot_originAuthenticationRequired(QWebSocketCorsAuthenticator *authenticator);
    void slot_peerVerifyError(const QSslError &error);
    void slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator);
    void slot_serverError(QWebSocketProtocol::CloseCode closeCode);
    void slot_sslErrors(const QList<QSslError> &errors);
    void slot_processTextMessage(const QString &message);
    void slot_processBinaryMessage(const QByteArray &message);
    void slot_socketConnected();
    void slot_socketDisconnected();
    void slot_error(QAbstractSocket::SocketError error);
    void slot_stateChanged(QAbstractSocket::SocketState state);

    void slot_tryReconnect();
    void slot_pingSockets();

private:
    void log(int severity, QString line);

private:
    NodeCoreInfo info;
    QHash<int, NodeRegistry*> sockets;
    int idsrc;
    DataBuffer* inbound_buffer;    // datablocks coming from the network
    DataBuffer* outbound_buffer;   // datablock are waiting to be sent
    DataBuffer* multi_buffer;      // buffer for multi sending

    QTimer* testtimer;
    QTimer* rc_timer;              // Socket reconnect timer
    QTimer* ping_timer;
    HSettings* settings;
};

#endif