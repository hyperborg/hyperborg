#ifndef BEACON_H
#define BEACON_H

#include <QObject>
#include <QUdpSocket>
#include <QStringList>
#include <QList>
#include <QTimer>
#include <QByteArray>
#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>
#include <QDebug>
#include <QNetworkDatagram>

class BeaconSocket : public QUdpSocket
{
Q_OBJECT
public:
    BeaconSocket(QObject *parent=nullptr);

signals:
    void matrixEcho(int port, int id, QString subnet="");

private slots:
    void readPendings();
    void processDatagram(QNetworkDatagram dgram);
};

class Beacon : public QObject
{
Q_OBJECT
public:
    Beacon(QObject *parent=NULL);
    ~Beacon();

    void setCurrentMatrix(int cm);
    void setupSockets();

signals:
    void matrices(QStringList lst);

private slots:
    void matrixDiscover();
    void matrixDiscovered(int port, int id, QString subnet);

private:
    QTimer disctimer;
    int _current_matrix;
    QList<BeaconSocket *> sockets;
};

#endif