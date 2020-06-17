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

void CoreServer::slot_originAuthenticationRequired(QWebSocketCorsAuthenticator* authenticator) 
{
    log(0, QString("CS: originAuthenticationRequired"));
}

void CoreServer::slot_peerVerifyError(const QSslError& error) 
{
    log(0, QString("CS: peerVerifyError %1").arg(error.errorString()));
}

//void CoreServer::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator) {}
void CoreServer::slot_serverError(QWebSocketProtocol::CloseCode closeCode) 
{
    log(0, QString("CS: serverError %1").arg(closeCode));
}

void CoreServer::slot_sslErrors(const QList<QSslError>& errors) 
{
    for (int i = 0; i < errors.count(); i++)
    {
        log(0, QString("CS: sslErrors %1").arg(errors.at(i).errorString()));
    }
}

void CoreServer::init()
{
    settings = HSettings::getInstance();
    rc_timer = new QTimer(this);
    QObject::connect(rc_timer, SIGNAL(timeout()), this, SLOT(slot_tryReconnect()));
    rc_timer->setSingleShot(true);

    QObject::connect(this, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(slot_acceptError(QAbstractSocket::SocketError)));
    QObject::connect(this, SIGNAL(closed()), this, SLOT(slot_closed()));
    QObject::connect(this, SIGNAL(newConnection()), this, SLOT(slot_newConnection()));
    QObject::connect(this, SIGNAL(originAuthenticationRequired(QWebSocketCorsAuthenticator *)), this, SLOT(slot_originAuthenticationRequired(QWebSocketCorsAuthenticator *)));
    QObject::connect(this, SIGNAL(peerVerifyError(const QSslError &)), this, SLOT(slot_peerVerifyError(const QSslError &)));
    QObject::connect(this, SIGNAL(preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)), this, SLOT(slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)));
    QObject::connect(this, SIGNAL(serverError(QWebSocketProtocol::CloseCode)), this, SLOT(slot_serverError(QWebSocketProtocol::CloseCode)));
    QObject::connect(this, SIGNAL(sslErrors(const QList<QSslError>&)), this, SLOT(slot_sslErrors(const QList<QSslError>&)));

    QSslConfiguration sslConfiguration;
    QFile certFile(settings->value(Conf_SslServerCert).toString());
    QFile keyFile(settings->value(Conf_SslServerKey).toString());
    certFile.open(QIODevice::ReadOnly);
    keyFile.open(QIODevice::ReadOnly);
    QSslCertificate certificate(&certFile, QSsl::Pem);
    QSslKey sslKey(&keyFile, QSsl::Rsa, QSsl::Pem);
    certFile.close();
    keyFile.close();
    sslConfiguration.setPeerVerifyMode(QSslSocket::VerifyNone);
    sslConfiguration.setLocalCertificate(certificate);
    sslConfiguration.setPrivateKey(sslKey);
    sslConfiguration.setProtocol(QSsl::TlsV1_2);
    setSslConfiguration(sslConfiguration);

}

void CoreServer::setRole(NodeCoreInfo _info)
{
    info = _info;
}

void CoreServer::setup(NodeCoreInfo _info)
{
    info = _info;
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
    log(0, QString("CS: acceptError: %1").arg(socketError));
}

void CoreServer::slot_closed()
{
    log(0, "SLOT_CLOSED");
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
            connect(ws, SIGNAL(sslErrors(QList<QSslError> &)), this, SLOT(slot_sslErrors(QList<QSslError> &)));
            ws->open(QUrl("wss://" + remotehost + ":" + port));
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

            if (info.noderole == NR_SLAVE && sockets.count() == 0)  // we lost connection to the master
            {
                rc_timer->start(60000); // try to reconnect in a minute 
            }
        }
    }
}

void CoreServer::slot_tryReconnect()
{
    connectToRemoteServer(info.ip, info.port);
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


