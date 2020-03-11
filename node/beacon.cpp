#include "beacon.h"

/* ----- BEACONSOCKET ------------------------------------------------------------------------------------ */

BeaconSocket::BeaconSocket(int port, QObject *parent) : QUdpSocket(parent), _port(port)
{
    connect(this, &QUdpSocket::readyRead, this, &BeaconSocket::readPendings);
    _sessionid = QString::number(QRandomGenerator::global()->generate());
    qDebug() << "GENERATED SESSION ID FOR PORT " << port << " IS " << _sessionid;
}

BeaconSocket::~BeaconSocket()
{
}

int BeaconSocket::port()
{
    return _port;
}

void BeaconSocket::readPendings()
{
    while (hasPendingDatagrams())
    {
        QNetworkDatagram datagram = this->receiveDatagram();
        processDatagram(datagram);
    }
}

void BeaconSocket::ping()
{
    qDebug() << "	--> beacon ping for port " << port();
    QNetworkDatagram dg;
    QString payload = "HYPERBORG#"+_sessionid;
    QByteArray ba = payload.toUtf8();
    dg.setData(ba);
    dg.setDestination(QHostAddress::Broadcast, port());
    writeDatagram(dg);
}

void BeaconSocket::processDatagram(QNetworkDatagram dgram)
{
    QByteArray array = dgram.data();
    QString str(array);
    if (str.contains("HYPERBORG"))
    {
	qDebug() << "UNIMATRIX NODE [] FOUND ON PORT " << port() << " SENDER: " << dgram.senderAddress().toString();
	QString data=QString(dgram.data());
	QStringList lst=data.split("#");
	if ((lst.count()==2) && (lst[0]=="HYPERBORG"))
	{
	    qDebug() << "-- reply came not from myself!";
	}
    }
}

/* ----- BEACON -------------------------------------------------------------------------------------------- */

Beacon::Beacon(QObject *parent) : QObject(parent), _current_matrix(-1)
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
    disctimer->start(1000*60);	// every minute
    QMetaObject::invokeMethod(this, "discoverMatrix"); // enqueu one now so we should not wait 1 minute
}

void Beacon::setCurrentMatrix(int cm)
{
    _current_matrix = cm;
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
        QObject::connect(socket, SIGNAL(matrixEcho(int, int, QString, QString)), this, SLOT(matrixDiscovered(int, int, QString, QString)));
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

void Beacon::matrixDiscovered(int port, int id, QString cmd, QString subnet)
{
    qDebug() << "MATRIX DISCOVERED at port: " << port << " ID: " << id << "  subnet: " << subnet << " with CMD: " << cmd;
}



