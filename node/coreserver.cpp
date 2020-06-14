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
                connect(ws, &QWebSocket::connected, this, &CoreServer::slot_socketConnected);
                connect(ws, &QWebSocket::disconnected, this, &CoreServer::slot_socketDisconnected);
                connect(ws, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_error(QAbstractSocket::SocketError)));
                log(0, QString("New connection from %1 registered with ID: %2").arg(ws->peerAddress().toString()).arg(nr->id));
            }
        }
    }
}

void CoreServer::connectToRemoteServer(QString remotehost, QString port)
{
    if (QWebSocket* ws = new QWebSocket())
    {
        if (NodeRegistry* nr = new NodeRegistry(idsrc, ws))
        {
            ws->setProperty("ID", nr->id);
            sockets.insert(nr->id, nr);
            connect(ws, &QWebSocket::textMessageReceived, this, &CoreServer::slot_processTextMessage);
            connect(ws, &QWebSocket::binaryMessageReceived, this, &CoreServer::slot_processBinaryMessage);
            connect(ws, &QWebSocket::connected, this, &CoreServer::slot_socketConnected);
            connect(ws, &QWebSocket::disconnected, this, &CoreServer::slot_socketDisconnected);
            connect(ws, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_error(QAbstractSocket::SocketError)));
            ws->open(QUrl("ws://" + remotehost + ":" + port));
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
            datablock->isText = true;
            log(0, QString("Text message arrived from %1 id:%2 length: %3").arg(ws->peerAddress().toString()).arg(datablock->socketid).arg(datablock->text_payload.length()));
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
            datablock->binary_payload = message;
            datablock->isText = false;
            log(0, QString("Binary message arrived from %1 id:%2 length: %3").arg(ws->peerAddress().toString()).arg(datablock->socketid).arg(datablock->text_payload.length()));
            emit incomingData(datablock);
        }
    }
}
void CoreServer::slot_socketConnected()
{
    log(0, "Slave socket is connected to remote server");
}

void CoreServer::slot_error(QAbstractSocket::SocketError err)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        int id = ws->property("ID").toInt();
        if (NodeRegistry* nr = sockets.take(id))
        {
            log(0, QString("Socket has error ip: %1 id: %2 error: %3").arg(ws->peerAddress().toString()).arg(nr->id).arg(ws->errorString()));
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
            log(0, QString("Node disconnected ip: %1 id: %2").arg(ws->peerAddress().toString()).arg(id));
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


