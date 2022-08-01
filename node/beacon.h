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
#include "common_network.h"
#include "hfs.h"

class BeaconSocket : public QUdpSocket
{
Q_OBJECT
public:
    BeaconSocket(QObject *parent=nullptr);
    ~BeaconSocket();

    void ping();

private slots:
    void readPendings();
    void processDatagram(QNetworkDatagram dgram);
    void log(int severity, QString logline);

signals:
    void logLine(int severity, QString logline, QString src);

private:
    QString _sessionid;
    QByteArray ping_payload;
};

class Beacon : public QObject
{
Q_OBJECT
public:
    Beacon(HFS *hfs, QObject *parent=NULL);
    ~Beacon();

public slots:
    void init();
    void setBeaconEnabled(bool flag);
    void setElementProperty(QString path, QVariant value, int col=0);

signals:
    void matrices(QStringList lst);

private slots:
    void broadCastPing();
    void log(int severity, QString str, QString source="BEACON");

private:
    HFS* hfs;
    QTimer *btimer;
    BeaconSocket *bsocket;  // Broadcasting socket
    BeaconSocket* dsocket;  // Discovery (binding) socket

    // beacon params (only one for this time, no multiple interface support)
    QString _matrix;		// uniqe id of matrix we are participating in. If this is empty, we do not know yet where to bind.
    QString _role;          // the role of this node in the mesh network
    QString _nodeid;
    QString _ip;
    QString _port;          // where the actual communication would take place
    QString _version;
    QString _build_date;
    QString sessionid;
};

#endif