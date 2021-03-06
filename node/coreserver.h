#ifndef CORESERVER_H
#define CORESERVER_H

#include <QObject>
#include <QWebSocketServer>
#include <QSslError>
#include <QSslConfiguration>
#include <QSslKey>
#include <QProcess>

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
#include "common_network.h"
#include "buffer.h"
#include "hsettings.h"

class CoreServer : public QWebSocketServer
{
Q_OBJECT
public:
    CoreServer(QString servername, QWebSocketServer::SslMode securemode, int port, QObject *parent=nullptr);
    ~CoreServer();

    void setInboundBuffer(PackBuffer* b) { inbound_buffer = b; }
    void setOutbountBuffer(PackBuffer* b) { outbound_buffer = b; }

public slots:
    void init();
    void setup(NodeCoreInfo info);
    void setRole(NodeCoreInfo info);
    void newData();
    void connectToRemoteServer(QString remoteserver, QString port);

signals:
    void logLine(int severity, QString line, QString source);
    void incomingData(DataPack *block);

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
    void slot_sendPacksOut();

private:
    void log(int severity, QString line);

private:
    NodeCoreInfo info;
    QHash<int, NodeRegistry*> sockets;
    int idsrc;
    int mastersocket_id;	   // Socket id used by the master (only relevant in slave mode)
    PackBuffer* inbound_buffer;    // DataPacks coming from the network
    PackBuffer* outbound_buffer;   // DataPack are waiting to be sent
    PackBuffer* multi_buffer;      // buffer for multi sending

    QString _remote_host;	   // URL of where the application should connect
    QString _remote_port;

    QTimer* testtimer;
    QTimer* rc_timer;              // Socket reconnect timer
    QTimer* ping_timer;
    HSettings* settings;
};

#endif