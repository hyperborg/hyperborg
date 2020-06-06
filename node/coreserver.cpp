#include "coreserver.h"

CoreServer::CoreServer(QString servername, QWebSocketServer::SslMode securemode, int port, QObject *parent)
: QWebSocketServer(servername, securemode, parent), idsrc(0)
{
}

CoreServer::~CoreServer()
{
}

void CoreServer::log(int severity, QString line)
{
    emit logLine(severity, line);
}

void CoreServer::slot_originAuthenticationRequired(QWebSocketCorsAuthenticator* authenticator) {}
void CoreServer::slot_peerVerifyError(const QSslError& error) {}
//void CoreServer::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator) {}
void CoreServer::slot_serverError(QWebSocketProtocol::CloseCode closeCode) {}
void CoreServer::slot_sslErrors(const QList<QSslError>& errors) {}

void CoreServer::init()
{
    QObject::connect(this, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(slot_acceptError(QAbstractSocket::SocketError)));
    QObject::connect(this, SIGNAL(closed()), this, SLOT(slot_closed()));
    QObject::connect(this, SIGNAL(newConnection()), this, SLOT(slot_newConnection()));
    QObject::connect(this, SIGNAL(originAuthenticationRequired(QWebSocketCorsAuthenticator *)), this, SLOT(slot_originAuthenticationRequired(QWebSocketCorsAuthenticator *)));
    QObject::connect(this, SIGNAL(peerVerifyError(const QSslError &)), this, SLOT(slot_peerVerifyError(const QSslError &)));
//    QObject::connect(this, SIGNAL(preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)), this, SLOT(slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)));
    QObject::connect(this, SIGNAL(serverError(QWebSocketProtocol::CloseCode)), this, SLOT(slot_serverError(QWebSocketProtocol::CloseCode)));
    QObject::connect(this, SIGNAL(sslErrors(const QList<QSslError>&)), this, SLOT(slot_sslErrors(const QList<QSslError>&)));

}

void CoreServer::setup(NodeCoreInfo info)
{
    this->info = info;
    setServerName("hserver");
    if (!info.port.isEmpty())
    {
        if (listen(QHostAddress::Any, info.port.toInt()))
        {
            log(0, "Listening on port " + info.port);
        }
        else
        {
            log(0, "Cannot listen on given port: " + info.port);
        }
    }

}

void CoreServer::slot_acceptError(QAbstractSocket::SocketError socketError)
{
}

void CoreServer::slot_closed()
{
}

void CoreServer::slot_newConnection()
{
    while (hasPendingConnections())
    {
        if (QWebSocket* ws = nextPendingConnection())
        {
            if (NodeRegistry* nr = new NodeRegistry(idsrc, ws))
            {
                ws->setProperty("ID", nr->id);
                sockets.insert(nr->id, nr);
                connect(ws, &QWebSocket::textMessageReceived, this, &CoreServer::slot_processTextMessage);
                connect(ws, &QWebSocket::binaryMessageReceived, this, &CoreServer::slot_processBinaryMessage);
                connect(ws, &QWebSocket::disconnected, this, &CoreServer::slot_socketDisconnected);
            }
        }
    }
}

void CoreServer::slot_processTextMessage(const QString& message)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        if (DataBlock* datablock = new DataBlock())
        {
            datablock->socketid = ws->property("ID").toInt();
            datablock->text_payload = message;
            emit incomingData(datablock);
        }
    }
}

void CoreServer::slot_processBinaryMessage(const QByteArray& message)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        if (DataBlock* datablock = new DataBlock())
        {
            datablock->socketid = ws->property("ID").toInt();
            datablock->text_payload = message;
            emit incomingData(datablock);
        }
    }
}

void CoreServer::slot_socketDisconnected()
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        int id = ws->property("ID").toInt();
        if (NodeRegistry* nr = sockets.take(id))
        {
            sockets.remove(id);
            ws->deleteLater();
            delete(nr);
        }
    }
}

void CoreServer::newData()
{
    log(0, "CS: newData");
    int p = 1;
    while (p)
    {
        p = 0;
        if (DataBlock* block = outbound_buffer->takeFirst())
        {
            log(0, "CS: blockin outbound");
            p++;
            emit incomingData(block);
        }
    }
}


