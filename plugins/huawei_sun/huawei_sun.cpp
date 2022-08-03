#include <huawei_sun.h>

huawei_sun::huawei_sun(QObject *parent) : HyObject(parent),
_initialized(false), sock(NULL)
{
    QObject::connect(&reconnect_timer, SIGNAL(timeout()), this, SLOT(connectToRealDevice()));
    reconnect_timer.setSingleShot(true);
    QObject::connect(&readout_timer, SIGNAL(timeout()), this, SLOT(readOut()));
    readout_timer.setSingleShot(false);
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

    reconnect_timer.start(100);
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
    readout_timer.start(1000);
}

void huawei_sun::disconnected()
{
   _initialized = false;
}

void huawei_sun::stateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        reconnect_timer.start(15 * 1000);       // trying to reconnect in 30 secs
    }
}

void huawei_sun::readOut()
{
    MBAPackage mba;
    mba.func_code = MODBUS_READ;
    mba.register_address = 40525;
    sock->write(mba.encode());
    sock->flush();
}

void huawei_sun::connectToRealDevice()
{
    bool ok;
    if (sock->state() != QAbstractSocket::ConnectedState)
    {
//        sock->connectToHost(_host, _port.toInt(&ok));
        sock->connectToHost("192.168.37.161", 502);
    }
}

void huawei_sun::readyRead()
{
    // This is a TCP socket. We might want to implement some kind of buffering in case 
    // the transmission is fragmented. But with nowadays hardware, it should not happen.
    // We are talking about 20-30 bytes packages. For now, if cannot be encoded, we just drop.

    QByteArray ba = sock->readAll();
    MBAPackage mba;
    mba.decode(ba);
}


/* MBAPACKAGE ==========================================================*/

MBAPackage::MBAPackage()
{
    trid                = 1;
    prottype            = 0;
    logic_dev_id        = 1;
    func_code           = MODBUS_ERROR;
    register_address    = 0;
    register_value      = 0;
    error_code          = 0;
    data_length         = 6;
    number_of_registers = 2;
}

MBAPackage::~MBAPackage()
{
}

QByteArray MBAPackage::encode()
{
    QByteArray ba;
    ba.append(((uchar *)&trid)[1]);
    ba.append(((uchar*)&trid)[0]);
    ba.append(((uchar*)&prottype)[1]);
    ba.append(((uchar*)&prottype)[0]);
    ba.append(((uchar*)&data_length)[1]);
    ba.append(((uchar*)&data_length)[0]);
    ba.append((uchar)logic_dev_id);
    ba.append((uchar)func_code);
    ba.append(((uchar*)&register_address)[1]);
    ba.append(((uchar*)&register_address)[0]);
    ba.append(((uchar*)&number_of_registers)[1]);
    ba.append(((uchar*)&number_of_registers)[0]);

    qDebug() << "toHex1: " << ba.toHex();

return ba;
}

bool MBAPackage::decode(QByteArray ba)
{
    bool retbool = false;
    if (ba.size() < 9)
    {
        // return package is too small
        return retbool;
    }
    trid = ba.mid(0, 2).toUShort();
    prottype = ba.mid(2, 2).toUShort();
    data_length = ba.mid(4, 2).toUShort();
    logic_dev_id = ba.at(5);
    func_code = ba.at(6);
    if (func_code == MODBUS_ERROR)
    {
        error_code = ba.at(8);
        retbool = true;
    }
    else
    {
        data_length = ba.at(8);
        if (ba.size() == data_length + 9)
        {
            register_value = ba.mid(9, data_length);
            retbool = true;
        }
    }
    return retbool;
}

