#include "beacon.h"

/* ----- BEACONSOCKET ------------------------------------------------------------------------------------ */

BeaconSocket::BeaconSocket(int port, QObject *parent) : QUdpSocket(parent), _port(port)
{
    connect(this, &QUdpSocket::readyRead, this, &BeaconSocket::readPendings);
    _sessionid = QString::number(QRandomGenerator::global()->generate());
    qDebug() << "GENERATED SESSION ID FOR PORT " << port << " IS " << _sessionid;
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
    qDebug() << "	--> beacon ping for port " << port();
    QNetworkDatagram dg;
    QString payload = "HYPERBORG#"+_sessionid+"#"+_matrixid+"#"+_noderole+"#"+_nodeid;
    QByteArray ba = payload.toUtf8();
    dg.setData(ba);
    dg.setDestination(QHostAddress::Broadcast, port());
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
	if ((lst.count()==4) && (lst[0]=="HYPERBORG") && (lst[1]!=_sessionid))
	{
	    QString sessionid=lst.at(1);
	    QString matrixid=lst.at(2);
	    QString noderole=lst.at(3);
	    QString nodeid=lst.at(4);
	    qDebug() << "UNIMATRIX NODE ["<< matrixid <<"] FOUND ON PORT " << port() << " SENDER: " << dgram.senderAddress().toString() << "ROLE: " << noderole << " NODEID: " << nodeid;
	    emit matrixEcho(matrixid, nodeid, noderole, _ip, port());
	}
    }
}

/* ----- BEACON -------------------------------------------------------------------------------------------- */

Beacon::Beacon(QObject *parent) : QObject(parent)
{
}

Beacon::~Beacon()
{}

void Beacon::init()
{
    qDebug() << "Beacon - init";
    disctimer = new QTimer();
    connect(disctimer, SIGNAL(timeout()), this, SLOT(discoverMatrix()));
    disctimer->setSingleShot(false);
}

void Beacon::setMatrixAndRole(QString matrixid, QString role)
{
    _matrix = matrixid;
    _role = role;
    QMetaObject::invokeMethod(this, "discoverMatrix"); // enqueu one now so we should not wait 1 minute
}

void Beacon::setupSockets()
{
    // clear already existing sockets
    for (int i=0;i<sockets.count();i++)
    {
        sockets.at(i)->close();
        sockets.at(i)->deleteLater();
    }
    sockets.clear();
    for (int i=0;i<5;i++)
    {
	int port = 33333+i;
        BeaconSocket *socket = new BeaconSocket(port, this);
        socket->bind(QHostAddress::Broadcast, port , QAbstractSocket::ShareAddress);
        QObject::connect(socket, SIGNAL(matrixEcho(QString, QString, QString, int)), this, SLOT(matrixDiscovered(QString, QString, QString, int)));
	sockets.append(socket);
    }
}

void Beacon::discoverMatrix()
{
    qDebug() << "--discoverMatrix --";
    if (!sockets.count())
    {
	setupSockets();
    }
    for (int i=0;i<sockets.count();i++)
    {
	sockets.at(i)->ping();
    }
}

void Beacon::matrixDiscovered(QString matrixid, QString nodeid, QString noderole, QString nodeip, int port)
{
    qDebug() << "MATRIX DISCOVERED at port: " << port << " Matrix ID: " << matrixid << "  NodeId: " << nodeid << " with IP: " << nodeip;
}

void Beacon::setSelectedMatrix(int port, QString matrixid)
{
    QList<BeaconSocket *> removedsockets;
    for (int i=0;i<sockets.count();++i)
    {
	BeaconSocket *bs=sockets.at(i);
	if (bs->port()!=port)
	{
	    removedsockets.append(bs);
	}
	else
	{
	    bs->setMatrixId(matrixid, _role, "0", "0.0.0.0");
	}
    }
    for (int i=0;i<removedsockets.count();i++)
    {
	BeaconSocket *bs=removedsockets.at(i);
	sockets.removeAll(bs);
	bs->close();
	bs->deleteLater();
    }
}

