#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent) : QTcpSocket(parent)
{
    waits << 1 << 1 << 5 << 10 << 10 << 60 << 60;
    attempts=0;
    QObject::connect(this, SIGNAL(connected()), this, SLOT(_connected()));
    QObject::connect(this, SIGNAL(disconnected()), this, SLOT(_disconnected()));
    QObject::connect(this, SIGNAL(hostFound()), this, SLOT(_hostFound()));
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(reconnect()));
    timer.setSingleShot(true);
}

TcpSocket::~TcpSocket()
{
}

void TcpSocket::_connected()
{
    attempts = 0;
    _host = peerAddress();
    _port = peerPort();
}

void TcpSocket::_disconnected()
{
}

void TcpSocket::_errorOccurred(QAbstractSocket::SocketError socketError)
{
    attempts++;
    attempts=attempts%waits.count()-1;
    timer.stop();
    int to = waits.at(attempts)*1000;
    timer.start(waits.at(attempts)*1000);
}

void TcpSocket::_hostFound()
{
}

void TcpSocket::_stateChanged(QAbstractSocket::SocketState socketState)
{
}

void TcpSocket::_proxyAuthenticationRequired(const QNetworkProxy& proxy, QAuthenticator* authenticator)
{
}

void TcpSocket::_readyRead()
{
}

void TcpSocket::reconnect()
{
    connectToHost(_host, _port);
}

void TcpSocket::disable()
{
    timer.stop();
    attempts=0;
    disconnect();
}