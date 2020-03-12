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

class BeaconSocket : public QUdpSocket
{
Q_OBJECT
public:
    BeaconSocket(int port, QObject *parent=nullptr);
    ~BeaconSocket();

    void ping();
    int port();
    void setMatrixId(int id);

signals:
    void matrixEcho(int port, int id, QString cmd, QString subnet);

private slots:
    void readPendings();
    void processDatagram(QNetworkDatagram dgram);

private:
    int _port;
    QString _sessionid;
    QString _matrixid;
};

class Beacon : public QObject
{
Q_OBJECT
public:
    Beacon(QObject *parent=NULL);
    ~Beacon();

    void setRequiredMatrix(int id);
    void setCurrentMatrix(int cm);
    void setupSockets();

signals:
    void matrices(QStringList lst);

public slots:
    void init();
    void setSelectedMatrix(int port, int id);

private slots:
    void discoverMatrix();
    void matrixDiscovered(int port, int id, QString cmd, QString subnet);

private:
    QTimer *disctimer;
    int _current_matrix;		// uniqe id of matrix we are participating in. If this is -1, we do not know yet where to bind.
    QString _required_matrix;
    QList<BeaconSocket *> sockets;
};

#endif