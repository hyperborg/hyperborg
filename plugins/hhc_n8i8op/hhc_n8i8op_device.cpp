#include <hhc_n8i8op_device.h>

hhc_n8i8op_device::hhc_n8i8op_device(QObject *parent) : HDevice(parent)
{
    tcnt=0;
}

hhc_n8i8op_device::~hhc_n8i8op_device()
{
}

QJsonObject hhc_n8i8op_device::configurationTemplate()
{
    QJsonObject obj;
    return obj;
}

bool hhc_n8i8op_device::loadConfiguration(QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString())
        _name = json["name"].toString();
    if (json.contains("id") && json["id"].isString())
        _id = json["id"].toString();
    if (json.contains("host") && json["host"].isString())
        _host = json["host"].toString();
    if (json.contains("port") && json["port"].isString())
        _port = json["port"].toString();
    return true;
}

void hhc_n8i8op_device::saveConfiguration(QJsonObject &json)
{
    json["name"] = _name;
    json["id"]   = _id;
    json["host"] = _host;
    json["port"] = _port;
}

void hhc_n8i8op_device::init()
{
    sock = new TcpSocket(this);
    QObject::connect(sock, SIGNAL(readyRead()), this, SLOT(readyRead()));
    QObject::connect(sock, SIGNAL(connected()), this, SLOT(connected()));
    QObject::connect(sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    
    qDebug() << "device::init()";
    for (int i=0;i<8;i++)
    {
        HRelay *relay = new HRelay(this);
        relays.append(relay);
    }

    connectToRealDevice();

    ticktimer = new QTimer();
    QObject::connect(ticktimer, SIGNAL(timeout()), this, SLOT(ticktimeout()));
}

void hhc_n8i8op_device::setRelay(int idx, int status, int delay)
{
    if (idx<1 || idx>relays.count() || idx>8) return;
    QString cmd;
    if (status==0)      cmd = "off";
    else if (status==1) cmd = "on";
    else return;
    cmd+=QString::number(idx);
    if (delay>0)
    {
        cmd+=":";
        if (delay<10) cmd+="0";
        cmd+=QString::number(delay);
    }
}

void hhc_n8i8op_device::connected()
{
    qDebug() << "connected2";
    out_buffer << "on1";
    out_buffer << "read";
    out_buffer << "on2";
    out_buffer << "read";
    out_buffer << "on3";
    out_buffer << "read";
    out_buffer << "on4";
    out_buffer << "read";
    out_buffer << "on5";
    out_buffer << "read";
    out_buffer << "on6";
    out_buffer << "read";
    out_buffer << "on7";
    out_buffer << "read";
    out_buffer << "on8";
    out_buffer << "read";

    out_buffer << "off1";
    out_buffer << "read";
    out_buffer << "off2";
    out_buffer << "read";
    out_buffer << "off3";
    out_buffer << "read";
    out_buffer << "off4";
    out_buffer << "read";
    out_buffer << "off5";
    out_buffer << "read";
    out_buffer << "off6";
    out_buffer << "read";
    out_buffer << "off7";
    out_buffer << "read";
    out_buffer << "off8";
    out_buffer << "read";

    ticktimer->start(100);
}

void hhc_n8i8op_device::ticktimeout()
{
    tcnt++;
    tcnt=tcnt%out_buffer.count();
    sendCommand(out_buffer.at(tcnt));
}

void hhc_n8i8op_device::disconnected()
{
}

void hhc_n8i8op_device::setRelays(QString ascii_command)
{
}

void hhc_n8i8op_device::connectToRealDevice()
{
    bool ok;
    sock->connectToHost(_host, _port.toInt(&ok));
}

void hhc_n8i8op_device::sendCommand(QString cmd)
{
    qDebug() << "SEND: #" << cmd.toLocal8Bit() << "#";
    sock->write(cmd.toLocal8Bit());
    sock->flush();
}

void hhc_n8i8op_device::readyRead()
{
    qDebug() << " ----------------- READYREAD -------------------------- ";
    in_buffer+=QString(sock->readAll());
    qDebug() << in_buffer;
    in_buffer="";
}
