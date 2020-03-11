#include "coreserver.h"

CoreServer::CoreServer(QString servername, QWebSocketServer::SslMode securemode, int port, QObject *parent) 
: QWebSocketServer(servername, securemode, parent), _port(port)
{
}

CoreServer::~CoreServer()
{
}

void CoreServer::init()
{
    QObject::connect(this, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(acceptError(QAbstractSocket::SocketError)));
    QObject::connect(this, SIGNAL(closed()), this, SLOT(closed()));
    QObject::connect(this, SIGNAL(newConnection()), this, SLOT(newConnection()));
    QObject::connect(this, SIGNAL(originAuthenticationRequired(QWebSocketCorsAuthenticator *)), this, SLOT(originAuthenticationRequired(QWebSocketCorsAuthenticator *)));
    QObject::connect(this, SIGNAL(peerVerifyError(const QSslError &)), this, SLOT(peerVerifyError(const QSslError &)));
    QObject::connect(this, SIGNAL(preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)), this, SLOT(preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)));
    QObject::connect(this, SIGNAL(serverError(QWebSocketProtocol::CloseCode)), this, SLOT(serverError(QWebSocketProtocol::CloseCode)));
    QObject::connect(this, SIGNAL(sslErrors(const QList<QSslError>&)), this, SLOT(sslErrors(const QList<QSslError>&)));
}

void CoreServer::acceptError(QAbstractSocket::SocketError socketError)
{
}

void CoreServer::closed()
{
}

void CoreServer::newConnection()
{
}

void CoreServer::originAuthenticationRequired(QWebSocketCorsAuthenticator *authenticator)
{
}

void CoreServer::peerVerifyError(const QSslError &error)
{
}

void CoreServer::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator)
{
}

void CoreServer::serverError(QWebSocketProtocol::CloseCode closeCode)
{
}

void CoreServer::sslErrors(const QList<QSslError> &errors)
{
}
