#include "beacon.h"

BeaconSocket::BeaconSocket(QObject *parent) : QUdpSocket(parent)
{
    connect(this, &QUdpSocket::readyRead, this, &BeaconSocket::readPendings);
}

void BeaconSocket::readPendings()
{
    while (hasPendingDatagrams())
    {
        QNetworkDatagram datagram = this->receiveDatagram();
        processDatagram(datagram);
    }
}

void BeaconSocket::processDatagram(QNetworkDatagram dgram)
{
    QByteArray array = dgram.data();
}


Beacon::Beacon(QObject *parent) : QObject(parent), _current_matrix(0)
{
    connect(&disctimer, SIGNAL(timeout()), this, SLOT(discoverMatrix()));
    disctimer.setSingleShot(false);
    disctimer.start(1000*60);	// every minute
    QMetaObject::invokeMethod(this, "discoverMatrix"); // enqueu one now so we should not wait 1 minute
}

Beacon::~Beacon()
{}

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
        BeaconSocket *socket = new BeaconSocket(this);
        socket->bind(QHostAddress::Broadcast, 33333+i, QAbstractSocket::ShareAddress);
        QObject::connect(socket, SIGNAL(matrixEcho(int, int, QString)), this, SLOT(matrixDiscovered(int, int, QString)));
    }
}

void Beacon::matrixDiscover()
{
    for (int i=0;i<sockets.count();i++)
    {
    }
}

void Beacon::matrixDiscovered(int port, int id, QString subnet)
{
    qDebug() << "MATRIX DISCOVERED at port: " << port << " ID: " << id << "  subnet: " << subnet;
}
