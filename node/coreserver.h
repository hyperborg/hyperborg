#ifndef CORESERVER_H
#define CORESERVER_H

#include <QObject>
#include <QWebSocketServer>
#include <QSslError>
//#include <QSslPreSharedKeyAuthenticator>
#include <QHash>
#include <QString>
#include <QByteArray>
#include <QWebSocket>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>

#include "common.h"
#include "buffer.h"

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
    void newData();

signals:
    void logLine(int severity, QString line);
    void incomingData(DataBlock* datablock);

private slots:
    void slot_acceptError(QAbstractSocket::SocketError socketError);
    void slot_closed();
    void slot_newConnection();
    void slot_originAuthenticationRequired(QWebSocketCorsAuthenticator *authenticator);
    void slot_peerVerifyError(const QSslError &error);
//    void slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator);
    void slot_serverError(QWebSocketProtocol::CloseCode closeCode);
    void slot_sslErrors(const QList<QSslError> &errors);
    void slot_processTextMessage(const QString &message);
    void slot_processBinaryMessage(const QByteArray &message);
    void slot_socketDisconnected();

private:
    void log(int severity, QString line);

private:
    NodeCoreInfo info;
    QHash<int, NodeRegistry*> sockets;
    int idsrc;
    DataBuffer* inbound_buffer;    // datablocks coming from the network
    DataBuffer* outbound_buffer;   // datablock are waiting to be sent
    QTimer* testtimer;
};

#endif