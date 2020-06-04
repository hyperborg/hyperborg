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

#include "common.h"

class CoreServer : public QWebSocketServer
{
Q_OBJECT
public:
    CoreServer(QString servername, QWebSocketServer::SslMode securemode, int port, QObject *parent=nullptr);
    ~CoreServer();

public slots:
    void init();
    void setup(NodeCoreInfo info);
    void outgoingData(DataBlock* datablock);

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
};

#endif