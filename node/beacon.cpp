#include "beacon.h"

/* ----- BEACONSOCKET ------------------------------------------------------------------------------------ */

BeaconSocket::BeaconSocket(NodeCoreInfo info,  QObject* parent) 
: QUdpSocket(parent)
{
    info.sessionid = QString::number(QRandomGenerator::global()->generate());
    connect(this, &QUdpSocket::readyRead, this, &BeaconSocket::readPendings);
    
    QStringList tlst;
    tlst << "HB";
    tlst << "1";
    tlst << info.sessionid;
    tlst << info.matrixid;
    tlst << info.noderole;
    tlst << info.nodeid;
    tlst << info.port;
    tlst << info.ip;
    tlst << info.version;
    tlst << info.build_date;
    ping_payload = tlst.join("#").toUtf8();
}

BeaconSocket::~BeaconSocket()
{
}

void BeaconSocket::readPendings()
{
    while (hasPendingDatagrams())
    {
        QNetworkDatagram datagram = receiveDatagram();
        processDatagram(datagram);
    }
}

void BeaconSocket::ping()
{
    QNetworkDatagram dg;
    dg.setData(ping_payload);
    dg.setDestination(QHostAddress::Broadcast, 33333);
    writeDatagram(dg);
}

void BeaconSocket::processDatagram(QNetworkDatagram dgram)
{
    // Sender information
    int remote_port = dgram.senderPort();
    QString remote_server = dgram.senderAddress().toString();
    remote_server = remote_server.replace("::ffff:", "");    // not nice, should handle better
    // Ping payload
    QByteArray array = dgram.data();
    QString str(array);
    if (str.mid(0,3)=="HB#")
    {
	    QStringList l=str.split("#");
	    if ((l.count()==10))
	    {
            if (l.at(2) != _sessionid)
            {
                NodeCoreInfo info;
                info.matrixid   = l.at(3);
                info.noderole   = l.at(4);
                info.nodeid     = l.at(5);
                info.ip         = remote_server;
                info.port       = l.at(7);
                info.version    = l.at(8);
                info.build_date = l.at(9);
                emit matrixEcho(info);
            }
            else log(0, "local broadcast echo");
	    }
    }
}

void BeaconSocket::log(int severity, QString logline)
{
    emit logLine(severity, logline, "BEACONSOCKET");
}

/* ----- BEACON -------------------------------------------------------------------------------------------- */

Beacon::Beacon(QObject *parent) : QObject(parent)
{
    bsocket = NULL;
    dsocket = NULL;
}

Beacon::~Beacon()
{}

void Beacon::init()
{
    log(0, "Beacon - init");
    btimer = new QTimer();
    connect(btimer, SIGNAL(timeout()), this, SLOT(broadCastPing()));
    btimer->setSingleShot(false);
}

void Beacon::setBeaconEnabled(bool flag)
{
    if (btimer)
    {
        if (flag) btimer->start(1000);
        else btimer->stop();
    }
}

void Beacon::setRole(NodeCoreInfo info)
{
    int _dport = 33333; // wired in value for discovery port 
    // clean up existing connections before continue with switching mode
    if (bsocket)
    {
        if (bsocket->state() == QAbstractSocket::ConnectedState) bsocket->disconnect();
        bsocket->deleteLater();
        bsocket = NULL;
    }

    if (dsocket)
    {
        if (dsocket->state() == QAbstractSocket::ConnectedState) dsocket->disconnect();
        dsocket->deleteLater();
        dsocket = NULL;
    }

    QStringList localaddr = HlocalAddresses();

    if (info.noderole == NR_UNDECIDED)
    {
        // In undecided mode we bind to port 33333 for about 5 seconds to intercept any ongoing broadcast messages from any existing matrices.
        // Only discovery socket is activated. 
        dsocket = new BeaconSocket(info, this);
        if (localaddr.count())
        {
            // We pick the first available address. It needs a finer selection method or should add more
            // sockets for binding and reporting
            //if (dsocket->bind(QHostAddress(localaddr.at(1)), 33333, QAbstractSocket::ShareAddress))
            if (dsocket->bind(QHostAddress::Any, 33333, QAbstractSocket::ShareAddress))
            {
                QObject::connect(dsocket, SIGNAL(matrixEcho(NodeCoreInfo)), this, SLOT(slot_matrixEcho(NodeCoreInfo)));
                QObject::connect(dsocket, SIGNAL(logLine(int, QString, QString)), this, SLOT(log(int, QString, QString)));
            }
            else
            {
                qDebug() << dsocket->error();
                log(0, QString("Discovery socket cannot bind to port %1").arg(info.port));
                dsocket->deleteLater(); 
                dsocket = NULL;
            }
        }
    }
    else if (info.noderole == NR_MASTER)
    {
        // When node is entered master role, it need to maintain only the broadcast socket
        bsocket = new BeaconSocket(info, this);
        QObject::connect(bsocket, SIGNAL(logLine(int, QString, QString)), this, SLOT(log(int, QString, QString)));
        setBeaconEnabled(true);
    }
    else if (info.noderole == NR_SLAVE)
    {
        setBeaconEnabled(false);
    }
    else
    {
        log(1, "Unknown noderole: " + info.noderole);
    }
}

void Beacon::log(int severity, QString str, QString source)
{
    if (source.isEmpty()) source="BEACON";
    emit logLine(severity, str, "BEACON");
}

void Beacon::slot_matrixEcho(NodeCoreInfo info )
{
//    log(0, QString("Matrix disocvered with id %1, nodeid: %2, ip: %3, port: %4").arg(info.matrixid).arg(info.nodeid).arg(info.ip).arg(info.port));
    emit matrixEcho(info);
}

void Beacon::broadCastPing()
{
    if (bsocket)
        bsocket->ping();
}

