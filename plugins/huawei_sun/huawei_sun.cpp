#include <huawei_sun.h>

huawei_sun::huawei_sun(QObject *parent) : HyObject(parent),
_initialized(false), sock(NULL)
{
    QObject::connect(&reconnect_timer, SIGNAL(timeout()), this, SLOT(connectToRealDevice()));
    reconnect_timer.setSingleShot(false);

    init();
}

huawei_sun::~huawei_sun()
{
}

void huawei_sun::init()
{
    if (sock)
    {
        sock->disconnect();
        sock->deleteLater();
        sock = NULL;
    }
    sock = new TcpSocket(this);
    QObject::connect(sock, SIGNAL(readyRead()), this, SLOT(readyRead()));
    QObject::connect(sock, SIGNAL(connected()), this, SLOT(connected()));
    QObject::connect(sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    QObject::connect(sock, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
}

QJsonObject huawei_sun::configurationTemplate()
{
    return QJsonObject();
}

void huawei_sun::saveConfiguration(QJsonObject& json)
{
    Q_UNUSED(json);
}

bool huawei_sun::loadConfiguration(QJsonObject json)
{
    Q_UNUSED(json);
    return true;
}

void huawei_sun::connected()
{
    printf("huawei_sun::connected\n");
  
}

void huawei_sun::disconnected()
{
   _initialized = false;
}

void huawei_sun::stateChanged(QAbstractSocket::SocketState socketState)
{
    return;
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        reconnect_timer.start(15 * 1000);       // trying to reconnect in 30 secs
    }
}

void huawei_sun::connectToRealDevice()
{
    bool ok;
    if (sock->state() != QAbstractSocket::ConnectedState)
    {
//        sock->connectToHost(_host, _port.toInt(&ok));
        sock->connectToHost("192.168.37.47", 502);
    }
}

void huawei_sun::readyRead()
{
}
