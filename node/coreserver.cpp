#include "coreserver.h"

CoreServer::CoreServer(HFS *_hfs, QString servername, QWebSocketServer::SslMode securemode, int port, QObject *parent)
: QObject(parent), // QWebSocketServer(servername, securemode, parent), 
  idsrc(0), mastersocket_id(-1), hfs(_hfs), noderole_master(-1), rc_timer(nullptr),
  serversocket(nullptr), inbound_buffer(nullptr), outbound_buffer(nullptr), testtimer(nullptr)
{
    hfs->provides(this, "cs.epochChanged()", HFS_LocalUsage);
    hfs->subscribe(this, System_Time_Epoch, "cs.epochChanged");
    hfs->subscribe(this, Bootup_NodeRole, "cs.nodeRoleChanged");
    hfs->dataChangeRequest(this, "", Bootup_NodeRole, hfs->data(Bootup_NodeRole).toString());
    device_name = hfs->data(Bootup_Name).toString();
}

CoreServer::~CoreServer()
{
}

void CoreServer::log(int severity, const QString &line)
{
    qDebug() << line << "\n";
    hfs->log(severity, line, "CORESERVER");
}

void CoreServer::slot_originAuthenticationRequired(QWebSocketCorsAuthenticator* auth)
{
    qDebug() << "slot_originAuthenticationRequired\n";
}

#if !defined(PF_WASM) && !defined(PF_ANDROID)
void CoreServer::slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator* auth)
{
    qDebug() << "slot_preSharedKeyAuthenticationRequired\n";
}
#endif

void CoreServer::slot_peerVerifyError(const QSslError& error)
{
    qDebug() << "slot_peerVerifyError\n";
}

void CoreServer::slot_sslErrors(const QList<QSslError>& lst)
{
    qDebug() << "slot_sslErrors\n";
}

void CoreServer::slot_serverError(QWebSocketProtocol::CloseCode closeCode)
{
    log(Info, QString("CS: serverError %1").arg(closeCode));
}

void CoreServer::nodeRoleChanged(Job *job)
{
 //   QString value = job->variant.toString();
    QString value = NR_SLAVE;
    if (value == NR_MASTER)         // Launch coreserver's server socket
    {
#if !PF_WASM && !PM_ANDROID
        serversocket.reset(new QWebSocketServer("server", QWebSocketServer::SecureMode));
        noderole_master = 1;
        int _port = hfs->data(Bootup_Port).toInt();
        if (_port)
        {
            log(Info, "Entering MASTER mode, listening on port:" + QString::number(_port));
            QObject::connect(serversocket.get(), SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(slot_acceptError(QAbstractSocket::SocketError)));
            QObject::connect(serversocket.get(), SIGNAL(closed()), this, SLOT(slot_closed()));
            QObject::connect(serversocket.get(), SIGNAL(newConnection()), this, SLOT(slot_newConnection()));
            QObject::connect(serversocket.get(), SIGNAL(originAuthenticationRequired(QWebSocketCorsAuthenticator*)), this, SLOT(slot_originAuthenticationRequired(QWebSocketCorsAuthenticator*)));
            QObject::connect(serversocket.get(), SIGNAL(peerVerifyError(const QSslError&)), this, SLOT(slot_peerVerifyError(const QSslError&)));
            QObject::connect(serversocket.get(), SIGNAL(serverError(QWebSocketProtocol::CloseCode)), this, SLOT(slot_serverError(QWebSocketProtocol::CloseCode)));
            QObject::connect(serversocket.get(), SIGNAL(sslErrors(const QList<QSslError>&)), this, SLOT(slot_sslErrors(const QList<QSslError>&)));

            QSslConfiguration sslConfiguration;
            QString certf = hfs->data(Bootup_SslServerCert).toString();
            QString keyf = hfs->data(Bootup_SslServerKey).toString();
            QFile certFile(certf);
            QFile keyFile(keyf);
            if (certFile.open(QIODevice::ReadOnly) && keyFile.open(QIODevice::ReadOnly))
            {
                QSslCertificate certificate(&certFile, QSsl::Pem);
                QSslKey sslKey(&keyFile, QSsl::Rsa, QSsl::Pem);
                sslConfiguration.setLocalCertificate(certificate);
                sslConfiguration.setPrivateKey(sslKey);
                certFile.close();
                keyFile.close();
            }
            sslConfiguration.setPeerVerifyMode(QSslSocket::VerifyNone);
            serversocket.get()->setSslConfiguration(sslConfiguration);
            serversocket.get()->listen(QHostAddress::Any, _port);
        }
        else
        {
            log(Info, "Cannot start listening! Port is not defined");
        }
#endif
     }
     else if (value== NR_SLAVE)
     {
        serversocket.reset();
        noderole_master = 0;
        int _port = hfs->data(Bootup_Port).toInt();
        QString _server = hfs->data(Bootup_IP).toString();
        if (_port == 0 || _server.isEmpty())
            log(Info, "Cannot enter SLAVE mode since port or remote host is not defined");
        else
            connectToRemoteServer(_server, QString::number(_port));
    }
}

void CoreServer::init()
{
    rc_timer = new QTimer(this);
    QObject::connect(rc_timer, SIGNAL(timeout()), this, SLOT(slot_tryReconnect()));
    rc_timer->setSingleShot(true);
    nodeRoleChanged(nullptr);
}

void CoreServer::slot_acceptError(QAbstractSocket::SocketError socketError)
{
    log(Info, QString("CS: acceptError: %1").arg(socketError));
}

void CoreServer::slot_closed()
{
    log(Info, "SLOT_CLOSED");
    if (hfs->nodeRole() == NR_SLAVE)
    {
        rc_timer->start(6000);
    }
}

void CoreServer::slot_newConnection()
{
    if (serversocket.isNull()) return;
    while (serversocket.get()->hasPendingConnections())
    {
        if (QWebSocket* ws = serversocket.get()->nextPendingConnection())
        {
            if (NodeRegistry* nr = new NodeRegistry(qMax(1, --idsrc), ws))
            {
                ws->setProperty("ID", nr->id);
                sockets.insert(nr->id, nr);
                connect(ws, &QWebSocket::textMessageReceived, this, &CoreServer::slot_processTextMessage);
                connect(ws, &QWebSocket::binaryMessageReceived, this, &CoreServer::slot_processBinaryMessage);
                connect(ws, &QWebSocket::connected, this, &CoreServer::slot_socketConnected);
                connect(ws, &QWebSocket::disconnected, this, &CoreServer::slot_socketDisconnected);
                connect(ws, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_error(QAbstractSocket::SocketError)));
                connect(ws, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slot_stateChanged(QAbstractSocket::SocketState)));
                log(Info, QString("New connection from %1 registered with ID: %2").arg(ws->peerAddress().toString()).arg(nr->id));

                if (DataPack* pack = new DataPack(SetSocketId))
                {
                    int did = hfs->devId();
                    pack->setSource(hfs->devId());
                    pack->setAttribute("socket_id", nr->id);
                    nr->addDataPack(pack);
                    devid_socket.insert(nr->id, nr->id);
                }
            }
        }
    }
    QMetaObject::invokeMethod(this, "slot_sendPacksOut", Qt::QueuedConnection);
}

void CoreServer::connectToRemoteServer(const QString &remotehost, const QString &port)
{
    if (remotehost.isEmpty()) return;
    _remote_host = remotehost;
    _remote_port = port;
    QString connectstr = "wss://" + remotehost + ":" + port;
    log(Info, QString("Attempt connection to remote server: %1").arg(connectstr));
    if (QWebSocket* ws = new QWebSocket(connectstr, QWebSocketProtocol::VersionLatest, this))
    {
        if (NodeRegistry* nr = new NodeRegistry(qMin(0,--idsrc), ws))
        {
            mastersocket_id=nr->id;
            nr->self = true;
            ws->setProperty("ID", nr->id);
            sockets.insert(nr->id, nr);
            int ccnt=0;
            if (connect(ws, &QWebSocket::textMessageReceived, this, &CoreServer::slot_processTextMessage)) ccnt+=1;
            if (connect(ws, &QWebSocket::binaryMessageReceived, this, &CoreServer::slot_processBinaryMessage)) ccnt+=2;
            if (connect(ws, &QWebSocket::connected, this, &CoreServer::slot_socketConnected)) ccnt+=4;
            if (connect(ws, &QWebSocket::disconnected, this, &CoreServer::slot_socketDisconnected)) ccnt+=8;
            if (connect(ws, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_error(QAbstractSocket::SocketError)))) ccnt+=16;
            if (connect(ws, SIGNAL(sslErrors(const QList<QSslError> &)), this, SLOT(slot_sslErrors(const QList<QSslError> &)))) ccnt+=32;
#if 0
            if (connect(this, SIGNAL(preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)), this, SLOT(slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)))) ccnt+=64;
            if (connect(ws, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slot_stateChanged(QAbstractSocket::SocketState)))) ccnt+=128;
#endif
            ws->open(QUrl(connectstr));
            log(Info, QString("connectToRemoteServer qtconn status: %1").arg(ccnt));
        }
    }
}

void CoreServer::slot_processBinaryMessage(const QByteArray& message)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        if (DataPack* pack = new DataPack())
        {
            pack->setSource(ws->property("ID").toInt());
            pack->_binary_payload = message;
            pack->_isText = false;
            emit incomingData(pack);
        }
    }
}

void CoreServer::slot_socketConnected()
{
    log(Info, "Slave socket is connected to remote server");
    hfs->setData(CS_ConnectionState, QAbstractSocket::ConnectedState);
    slot_pingSockets();
}

void CoreServer::slot_error(QAbstractSocket::SocketError err)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        int id = ws->property("ID").toInt();
        if (NodeRegistry* nr = sockets.value(id, nullptr))
        {
            log(Info, QString("Socket has error ip: %1 id: %2 error: %3").arg(ws->peerAddress().toString()).arg(nr->id).arg(ws->errorString()));
        }
    }
}

void CoreServer::slot_stateChanged(QAbstractSocket::SocketState state)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        int id = ws->property("ID").toInt();
        if (NodeRegistry* nr = sockets.value(id, nullptr))
        {
            if (nr->self)
            {
                hfs->setData("CS_ConnectionState", state);
            }
            log(Info, QString("Socket changed state: %1 id: %2").arg((int)state).arg(nr->id));
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
            log(Info, QString("Node disconnected ip: %1 id: %2").arg(ws->peerAddress().toString()).arg(id));
            sockets.remove(id);
            ws->deleteLater();
            devid_socket.remove(id);
            delete(nr);
            if (nr->self)
            {
                rc_timer->start(60 * 1000); // Try to reconnect in every minute
            }
        }
    }
}

void CoreServer::slot_tryReconnect()
{
    connectToRemoteServer(_remote_host, _remote_port);
}

void CoreServer::slot_processTextMessage(const QString& message)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        if (DataPack* pack = new DataPack(message))
        {
            DataPack::deserialize(pack);

            pack->setSocketId(ws->property("ID").toInt());

            qDebug() << "====================== NEW INCOMING PACKAGE =====================";
            qDebug() << "ORIGMSG: " << message;
            qDebug() << "COMMAND: " << pack->command();
            qDebug() << "SRC DEV: " << pack->sourceDevice();
            qDebug() << "SRC SCK: " << pack->socketId();
            qDebug() << "DST DEV: " << pack->destinationDevice();
            qDebug() << "PAYLOAD: " << pack->_text_payload;
            qDebug() << "=================================================================";

            if (pack->command() == Ping)
            {
                int src_dev = pack->sourceDevice();
                int soc_id = pack->socketId();

                //! POC
                //! This could be dangerous if a hostile node "lies" about his ID, it can steal
                //! or abrupt communication. Here will be added mutual authentication later on.
                //! This is minimal implementation for POC purposes

                if (devid_socket.contains(src_dev))
                {
                    if (devid_socket.value(src_dev) != soc_id)
                    {
                        devid_socket.remove(src_dev);
                        devid_socket.insert(src_dev, soc_id);
                    }
                }
                else
                {
                    devid_socket.insert(src_dev, soc_id);
                }
            }
            emit incomingData(pack);
        }
    }
}

void CoreServer::newData()
{
    // Dispatch package in multicast manner
    // Currently we do a deep copy of the incoming (and outbound) package for all active sockets
    // This has a performacne penalty and should use only one package with sent counter and socket mapping
    // but for now we do not expect more than 10 nodes in a standard network, thus it is fine
    // If it is need to streamline the dispatching method, it could be done without hurting the logic
    // NOTE: basic rule that we are not echoing back any package to the sender
    // NOTE: this implementation is expected to run only in the MASTER node at this version
    // The load balanced and distributed version as well as the toke-ring like versions are expected to
    // handle peacked distribution in a different manner

    // Here we do not care whether we are connected or not. If node is disconnected but knows its
    // role, the sent packages just automatically discarded and freed. The synchonization would
    // be handled at UniCore level when the connection is reeastablished.

    while (DataPack* pack = outbound_buffer->takeFirst())
    {
        if (noderole_master==0)     // slave
        {
            if (NodeRegistry *nr = sockets.value(mastersocket_id, nullptr))
            {
                nr->addDataPack(pack);
            }
            else
            {
                // NO connection is available at this moment, silently delete packet
                // Should notify upper layers about connection loss
                delete(pack);
            }
        }
        else if (noderole_master==1)    // master
        {
            int dest = pack->destinationDevice();
            if (dest!=-1)
            {
                int nridx = devid_socket.value(dest, -1);
                if (nridx != -1)
                {
                    if (NodeRegistry* reg = sockets.value(nridx, nullptr))
                    {
                        reg->addDataPack(new DataPack(pack));
                    }
                }

                // generate here all the ids for the sockets from the dest value
                // this would need an internal mapping so we could map the node ids
                // to the socket ids (keep in mind that socket ids could change)
                // For now we are just shouting out all incoming packets to all
                // connected nodes. We will finetune this later.
            }
            else
            {
                for (NodeRegistry *reg : sockets)
                {
                    if (reg)
                        reg->addDataPack(new DataPack(pack));
                }
            }
            delete(pack);
        }
        else if (noderole_master == -1)     // we are not connected
        {
        }
        else // other roles should be extended here, like VTRT (virtual token ring topology)
        {
            log(Info, QString("Role is undefined: %1").arg(noderole_master));
        }
    }
    slot_sendPacksOut();
}

void CoreServer::slot_sendPacksOut()
{
    for (NodeRegistry *nr : sockets)
    {
        if (nr->socket)
        {
            while (DataPack *dp = nr->getDataPack())
            {
                if (dp->isText())
                {
                    DataPack::serialize(dp);
                    nr->socket->sendTextMessage(dp->textPayload());
                }
                else
                {
                    nr->socket->sendBinaryMessage(dp->binaryPayload());
                }
                delete(dp);
            }
            nr->socket->flush();
        }
    }
}

QVariant CoreServer::epochChanged(Job *job)
{
    bool ok;
    int sec = job->variant.toInt(&ok);
    if (ok && sec%15==0)
    {
        slot_pingSockets();
    }

    return QVariant();
}

void CoreServer::slot_pingSockets()
{
    for (NodeRegistry *nr : sockets)
    {
        if (DataPack* pack = new DataPack(Ping))
        {
            int did = hfs->devId();
            pack->setSource(hfs->devId());
            nr->addDataPack(pack);
        }
    }
    slot_sendPacksOut();
}
