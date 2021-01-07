#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QTime>
#include <QHostAddress>

#include "common.h"

/*  TCPSocket
    Modified QTCPSocket so connection is always reconnected if lost.

*/

class TcpSocket : QTcpSocket
{
Q_OBJECT
public:
    TcpSocket(QObject *parent=nullptr);
    ~TcpSocket();

protected slots:
    void _connected();
    void _disconnected();
    void _errorOccurred(QAbstractSocket::SocketError socketError);
    void _hostFound();
    void _proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void _stateChanged(QAbstractSocket::SocketState socketState);
    void _readyRead();

    void reconnect();
    void disable();     // diconnects and disable reconnecting attempts

private:
    QHostAddress _host;
    quint16 _port;
    int attempts;
    QList<int> waits;   // secs to wait before next connection attempt is made
    QTime  time;
    QTimer timer;
};

#endif