#ifndef CORESERVER_H
#define CORESERVER_H

#include <QObject>
#include <QWebSocketServer>
#include <QSslError>
//#include <QSslPreSharedKeyAuthenticator>

class CoreServer : public QWebSocketServer
{
Q_OBJECT
public:
    CoreServer(QString servername, QWebSocketServer::SslMode securemode, int port, QObject *parent=nullptr);
    ~CoreServer();

public slots:
    void init();

private slots:
    void acceptError(QAbstractSocket::SocketError socketError);
    void closed();
    void newConnection();
    void originAuthenticationRequired(QWebSocketCorsAuthenticator *authenticator);
    void peerVerifyError(const QSslError &error);
//    void preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator);
    void serverError(QWebSocketProtocol::CloseCode closeCode);
    void sslErrors(const QList<QSslError> &errors);

private:
    int _port;
};

#endif