#include "coreserver.h"

CoreServer::CoreServer(QString servername, QWebSocketServer::SslMode securemode, int port, QObject *parent)
: QWebSocketServer(servername, securemode, parent), idsrc(0), mastersocket_id(-1)
{
}

CoreServer::~CoreServer()
{
}

void CoreServer::log(int severity, QString line)
{
    emit logLine(severity, line, "CORESERVER");
}

#if !defined(WASM)
void CoreServer::slot_originAuthenticationRequired(QWebSocketCorsAuthenticator* authenticator) 
{
    log(0, QString("CS: originAuthenticationRequired"));
    authenticator->setAllowed(true);
}

void CoreServer::slot_peerVerifyError(const QSslError& error) 
{
    log(0, QString("CS: peerVerifyError %1").arg(error.errorString()));
}

void CoreServer::slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator) 
{
    log(0, QString("CS: preSharedKeyAuthenticationRequired"));
    if (info.noderole == NR_SLAVE)
    {
        authenticator->setIdentity("client");
    }
    authenticator->setIdentity("client");
    authenticator->setPreSharedKey(QByteArray("hyperborg"));
}

#endif

void CoreServer::slot_serverError(QWebSocketProtocol::CloseCode closeCode) 
{
    log(0, QString("CS: serverError %1").arg(closeCode));
}

#if !defined(WASM)
void CoreServer::slot_sslErrors(const QList<QSslError>& errors) 
{
    for (int i = 0; i < errors.count(); i++)
    {
        log(0, QString("CS: sslErrors %1").arg(errors.at(i).errorString()));
    }
}
#endif

void CoreServer::init()
{
    settings = HSettings::getInstance();
    rc_timer = new QTimer(this);
    QObject::connect(rc_timer, SIGNAL(timeout()), this, SLOT(slot_tryReconnect()));
    rc_timer->setSingleShot(true);
    /*
        ping_timer=new QTimer(this);
        QObject::connect(ping_timer, SIGNAL(timeout()), this, SLOT(slot_pingSockets()));
        ping_timer->setSingleShot(false);
        ping_timer->start(10000);
    */
    QObject::connect(this, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(slot_acceptError(QAbstractSocket::SocketError)));
    QObject::connect(this, SIGNAL(closed()), this, SLOT(slot_closed()));
    QObject::connect(this, SIGNAL(newConnection()), this, SLOT(slot_newConnection()));
    QObject::connect(this, SIGNAL(originAuthenticationRequired(QWebSocketCorsAuthenticator*)), this, SLOT(slot_originAuthenticationRequired(QWebSocketCorsAuthenticator*)));
    QObject::connect(this, SIGNAL(peerVerifyError(const QSslError&)), this, SLOT(slot_peerVerifyError(const QSslError&)));
    QObject::connect(this, SIGNAL(preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator*)), this, SLOT(slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator*)));
    QObject::connect(this, SIGNAL(serverError(QWebSocketProtocol::CloseCode)), this, SLOT(slot_serverError(QWebSocketProtocol::CloseCode)));
    QObject::connect(this, SIGNAL(sslErrors(const QList<QSslError>&)), this, SLOT(slot_sslErrors(const QList<QSslError>&)));


#if !defined(WEBASSEMBLY)
    // For WebAssembly we do not load up any cert files since it might expose the private key to the public.
    // Most of the time, self-signed cert is fine -> mainly when deploying in-house systems.
    // Root-Signed cert should be provided for nodes accessible from internet (and that cert should match the domain name of the host)

    QSslConfiguration sslConfiguration;
    QString certf = settings->value(Conf_SslServerCert).toString();
    QString keyf = settings->value(Conf_SslServerKey).toString();
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
    sslConfiguration.setProtocol(QSsl::TlsV1_2);
    setSslConfiguration(sslConfiguration);
#endif
}

void CoreServer::setRole(NodeCoreInfo _info)
{
    log(0, QString("CS: setRole %1").arg(_info.noderole));
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
            if (NodeRegistry* nr = new NodeRegistry(qMax(1, ++idsrc), ws))
            {
                ws->setProperty("ID", nr->id);
                sockets.insert(nr->id, nr);
                connect(ws, &QWebSocket::textMessageReceived, this, &CoreServer::slot_processTextMessage);
                connect(ws, &QWebSocket::binaryMessageReceived, this, &CoreServer::slot_processBinaryMessage);
                connect(ws, &QWebSocket::connected, this, &CoreServer::slot_socketConnected);
                connect(ws, &QWebSocket::disconnected, this, &CoreServer::slot_socketDisconnected);
                connect(ws, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_error(QAbstractSocket::SocketError)));
                connect(ws, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slot_stateChanged(QAbstractSocket::SocketState)));
                log(0, QString("New connection from %1 registered with ID: %2").arg(ws->peerAddress().toString()).arg(nr->id));
            }
        }
    }
}

void CoreServer::connectToRemoteServer(QString remotehost, QString port)
{
    _remote_host = remotehost;
    _remote_port = port;
    QString connectstr = "wss://" + remotehost + ":" + port;
    if (QWebSocket* ws = new QWebSocket(connectstr, QWebSocketProtocol::VersionLatest, this))
    {
        if (NodeRegistry* nr = new NodeRegistry(qMax(1,++idsrc), ws))
        {
            mastersocket_id=nr->id;
            ws->setProperty("ID", nr->id);
            sockets.insert(nr->id, nr);
            int ccnt=0;
            if (connect(ws, &QWebSocket::textMessageReceived, this, &CoreServer::slot_processTextMessage)) ccnt+=1;
            if (connect(ws, &QWebSocket::binaryMessageReceived, this, &CoreServer::slot_processBinaryMessage)) ccnt+=2;
            if (connect(ws, &QWebSocket::connected, this, &CoreServer::slot_socketConnected)) ccnt+=4;
            if (connect(ws, &QWebSocket::disconnected, this, &CoreServer::slot_socketDisconnected)) ccnt+=8;
            if (connect(ws, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_error(QAbstractSocket::SocketError)))) ccnt+=16;
            if (connect(ws, SIGNAL(sslErrors(const QList<QSslError> &)), this, SLOT(slot_sslErrors(const QList<QSslError> &)))) ccnt+=32;
            if (QObject::connect(this, SIGNAL(preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)), this, SLOT(slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *)))) ccnt+=64;
            if (QObject::connect(ws, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slot_stateChanged(QAbstractSocket::SocketState)))) ccnt+=128;
#if !defined(WEBASSEMBLY)
            QSslConfiguration sslConfiguration;
            sslConfiguration.setPeerVerifyMode(QSslSocket::VerifyNone);
            sslConfiguration.setProtocol(QSsl::TlsV1_2);
            ws->setSslConfiguration(sslConfiguration);
#endif
            ws->open(QUrl(connectstr));
            log(0, QString("connectToRemoteServer qtconn status: %1").arg(ccnt));
        }
    }
}


void CoreServer::slot_processBinaryMessage(const QByteArray& message)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        if (DataPack* pack = new DataPack())
        {
            pack->_socketid = ws->property("ID").toInt();
            pack->_binary_payload = message;
            pack->_isText = false;
            log(0, QString("Binary message arrived from %1 id:%2 length: %3").arg(ws->peerAddress().toString()).arg(pack->_socketid).arg(pack->_text_payload.length()));
            emit incomingData(pack);
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
        if (NodeRegistry* nr = sockets.value(id, NULL))
        {
            log(0, QString("Socket has error ip: %1 id: %2 error: %3").arg(ws->peerAddress().toString()).arg(nr->id).arg(ws->errorString()));
        }
    }
}

void CoreServer::slot_stateChanged(QAbstractSocket::SocketState state)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        int id = ws->property("ID").toInt();
        if (NodeRegistry* nr = sockets.value(id, NULL))
        {
            log(0, QString("Socket changed state: %1 id: %2").arg((int)state).arg(nr->id));
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
    connectToRemoteServer(_remote_host, _remote_port);
}

void CoreServer::slot_processTextMessage(const QString& message)
{
    if (QWebSocket* ws = qobject_cast<QWebSocket*>(sender()))
    {
        if (DataPack* pack = new DataPack())
        {
            pack->_socketid = ws->property("ID").toInt();
            pack->_text_payload = message;
            pack->_isText = true;
            emit incomingData(pack);
        }
    }
}

void CoreServer::newData()
{
    int p = 1;
    if (p)
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

	while (DataPack* pack = outbound_buffer->takeFirst())
	{
	    if (info.noderole==NR_SLAVE)
	    {
		if (NodeRegistry *nr = sockets.value(mastersocket_id, NULL))
		{
		    log(0, QString("Added datapack to socket %1\n").arg(mastersocket_id));
		    nr->addDataPack(pack);
		}
		else
		{
		    log(0, QString("No active connection - pack is dropped: mid: %1  cs: %2\n").arg(mastersocket_id).arg(sockets.count()));
		    // NO connection is available at this moment, silently delete packet
		    // Should notify upper layers about connection loss
		    delete(pack);
		}
	    }
	    else if (info.noderole==NR_MASTER)
	    {
		QString dest = pack->destination();
		if (!dest.isEmpty())
		{
		    // generate here all the ids for the sockets from the dest value
		    // this would need an internal mapping so we could map the node ids 
		    // to the socket ids (keep in mind that socket ids could change)
		    // For now we are just shouting out all incoming packets to all
		    // connected nodes. We will finetune this later.
		}
		else
		{
		    QHashIterator<int, NodeRegistry *> it(sockets);
    		    while (it.hasNext())
    		    {
        		it.next();
            		it.value()->addDataPack(new DataPack(pack));
    		    }
		}
		delete(pack);
	    }
	    else // other roles should be extended here, like VTR (virtual token ring topology)
	    {
		log(0, QString("Role is undefined: %1\n").arg(info.noderole));
	    }
	}
    }
   else   // TESTING: channel back outbound message
    {
        if (DataPack* pack = outbound_buffer->takeFirst())
        {
	      emit incomingData(pack);
        }
    }
    slot_sendPacksOut();
}

void CoreServer::slot_sendPacksOut()
{
    QHashIterator<int, NodeRegistry *> it(sockets);
    while(it.hasNext())
    {
	it.next();
	NodeRegistry *nr = it.value();
	if (nr->socket)
	{
	    if (DataPack *dp = nr->getDataPack())
	    {
//		log(0, QString("Sending package out for: %1\n").arg(nr->id));
		if (dp->isText())
		{
		    nr->socket->sendTextMessage(dp->textPayload());
		}
		else
		{
		    nr->socket->sendBinaryMessage(dp->binaryPayload());
		}
	    }
	}
    }
}

void CoreServer::slot_pingSockets()
{
    QHashIterator<int, NodeRegistry *> s(sockets);
    while(s.hasNext())
    {
	s.next();
	s.value()->socket->sendTextMessage("PING\n\n");
	s.value()->socket->flush();
	log(0, QString("PING: %1").arg(s.value()->id));
    }
}

