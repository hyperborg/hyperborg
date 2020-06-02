#include "beacon.h"

/* ----- BEACONSOCKET ------------------------------------------------------------------------------------ */

BeaconSocket::BeaconSocket(int port, QObject *parent) : QUdpSocket(parent), _port(port)
{
    connect(this, &QUdpSocket::readyRead, this, &BeaconSocket::readPendings);
    _sessionid = QString::number(QRandomGenerator::global()->generate());
    log(0, QString("Generated sessionid for port %1 is %2").arg(port).arg(_sessionid));
    _matrixid=-1;
}

BeaconSocket::~BeaconSocket()
{
}

int BeaconSocket::port()
{
    return _port;
}

void BeaconSocket::setMatrixId(QString matrixid, QString role, QString nodeid, QString ip)
{
    _matrixid =matrixid;
    _noderole = role;
    _nodeid=nodeid;
    _ip=ip;
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
    QString payload = "HYPERBORG#"+_sessionid+"#"+_matrixid+"#"+_noderole+"#"+_nodeid;
    QByteArray ba = payload.toUtf8();
    dg.setData(ba);
    dg.setDestination(QHostAddress::Broadcast, 33333);
    writeDatagram(dg);
}

void BeaconSocket::processDatagram(QNetworkDatagram dgram)
{
    QByteArray array = dgram.data();
    QString str(array);
    if (str.mid(0,10)=="HYPERBORG#")
    {
	    QString data=QString(dgram.data());
	    QStringList lst=data.split("#");
	    if ((lst.count()==5) && (lst[0]=="HYPERBORG"))
	    {
            if (lst[1] != _sessionid)
            {
                QString sessionid = lst.at(1);
                QString matrixid = lst.at(2);
                QString noderole = lst.at(3);
                QString nodeid = lst.at(4);
//                log(0, QString("UNIMATRIX NODE [%1] FOUND ON PORT %2 SENDER: %3" << dgram.senderAddress().toString() << "ROLE: " << noderole << " NODEID: " << nodeid;
                emit matrixEcho(matrixid, nodeid, noderole, _ip, port());
            }
            else log(0, "local broadcast echo");
	    }
    }
}

void BeaconSocket::log(int severity, QString logline)
{
    emit logLine(severity, logline);
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

void Beacon::setRole(int role, QString matrixid, int port)
{
    _role = role;
    _matrix = matrixid;
    log(0, QString("Beacon::setRole role:%1, matrixid:%2, port:%3").arg(role).arg(matrixid).arg(port));
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

    switch (role)
    {
        case Undecided:
        {
            // In undecided mode we bind to port 33333 for about 5 seconds to intercept any ongoing broadcast messages from any existing matrices.
            // Only discovery socket is activated. 
            dsocket = new BeaconSocket(_dport, this);
            QStringList localaddr = localAddresses();
            localaddr.removeAll("127.0.0.1");
            if (localaddr.count())
            {
                // We pick the first available address. It needs a finer selection method or should add more
                // sockets for binding and reporting
                if (dsocket->bind(QHostAddress(localaddr.at(0)), 33333, QAbstractSocket::ShareAddress))
                {
                    QObject::connect(dsocket, SIGNAL(matrixEcho(QString, QString, QString, int)), this, SLOT(matrixDiscovered(QString, QString, QString, int)));
                    QObject::connect(dsocket, SIGNAL(logLine(int, QString)), this, SLOT(log(int, QString)));
                }
                else
                {
                    qDebug() << dsocket->error();
                    log(0, QString("Discovery socket cannot bind to port %1").arg(port));
                    dsocket->deleteLater();
                    dsocket = NULL;
                }
            }
        }
            break;
        case Master:
            // When node is entered master role, it need to maintain only the broadcast socket
            bsocket = new BeaconSocket(_dport, this);
            QObject::connect(bsocket, SIGNAL(logLine(int, QString)), this, SLOT(log(int, QString)));
            setBeaconEnabled(true);
            break;
        case Slave:
            break;
        default:
            break;
    }
}

void Beacon::log(int severity, QString str)
{
    emit logLine(severity, str);
}


void Beacon::matrixDiscovered(QString matrixid, QString nodeid, QString noderole, QString nodeip, int port)
{
    log(0, QString("Matrix disocvered with id %1, nodeid: %2, ip: %3, por: %d").arg(matrixid).arg(nodeid).arg(nodeip).arg(port));
}

void Beacon::broadCastPing()
{
    if (bsocket)
        bsocket->ping();
}

QStringList Beacon::localAddresses()
{
    QStringList lst;
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    for (int i = 0; i < interfaces.count(); i++)
    {
        if (interfaces.at(i).flags() & (QNetworkInterface::IsUp | QNetworkInterface::IsRunning))
        {
            QList<QNetworkAddressEntry> entries = interfaces.at(i).addressEntries();
            for (int j = 0; j < entries.count(); j++)
            {
                if (entries.at(j).ip().protocol() == QAbstractSocket::IPv4Protocol)
                {
                    lst.append(entries.at(j).ip().toString());
                }
            }
        }
    }
    return lst;
}
