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
#include <QHostAddress>
#include <QRandomGenerator>
#include <QNetworkAddressEntry>
#include <QNetworkInterface>

#include "common.h"

class BeaconSocket : public QUdpSocket
{
Q_OBJECT
public:
    BeaconSocket(int port, QObject *parent=nullptr);
    ~BeaconSocket();

    void ping();
    int port();
    void setMatrixId(QString matrixid, QString noderole, QString _nodeid, QString ip);

signals:
    void matrixEcho(QString matrixid, QString nodeid, QString noderole, QString ip, int port);
    void logLine(int severity, QString line);

private slots:
    void readPendings();
    void processDatagram(QNetworkDatagram dgram);
    void log(int severity, QString logline);
private:
    int _port;
    QString _sessionid;
    QString _matrixid;
    QString _noderole;
    QString _nodeid;
    QString _ip;
};

class Beacon : public QObject
{
Q_OBJECT
public:
    Beacon(QObject *parent=NULL);
    ~Beacon();


public slots:
    void init();
    void setRole(int role, QString matrixid, int port);
    void setBeaconEnabled(bool flag);


signals:
    void matrices(QStringList lst);
    void logLine(int severity, QString str);

private slots:
    void broadCastPing();
    void matrixDiscovered(QString matrixid, QString nodeid, QString noderole, QString nodeip, int port);
    void log(int severity, QString str);

private:
    QStringList localAddresses();

private:
    QTimer *btimer;
    QString _matrix;		// uniqe id of matrix we are participating in. If this is empty, we do not know yet where to bind.
    QString _role;
    int     _port;          // where the actual communication would take place
    BeaconSocket *bsocket;  // Broadcasting socket
    BeaconSocket* dsocket;  // Discovery (binding) socket
};

#endif