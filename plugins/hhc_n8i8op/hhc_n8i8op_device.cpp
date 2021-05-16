#include <hhc_n8i8op_device.h>

hhc_n8i8op_device::hhc_n8i8op_device(QObject *parent) : HDevice(parent), sock(NULL)
{
    tcnt=0;
    _named = false;
    _bypass = true;
    readregexp = QRegularExpression("(?i)((?<=[A-Z])(?=\\d))|((?<=\\d)(?=[A-Z]))");
    _delayed_timeout = 200;     // 200 ms for anti-buncing

    QObject::connect(&delayed_timer, SIGNAL(timeout()), this, SLOT(sendCommandDelayedTimeout()));
    delayed_timer.setSingleShot(true);
}

hhc_n8i8op_device::~hhc_n8i8op_device()
{
}

void hhc_n8i8op_device::sendCommandDelayed(QString str)
{
    delayed_timer.start(_delayed_timeout);
    _delayed_cmd = str;
}

void hhc_n8i8op_device::sendCommandDelayedTimeout()
{
    sendCommand(_delayed_cmd);
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
    if (sock)
    {
        sock->disconnect();
        sock->deleteLater();
    }
    sock = new TcpSocket(this);
    QObject::connect(sock, SIGNAL(readyRead()), this, SLOT(readyRead()));
    QObject::connect(sock, SIGNAL(connected()), this, SLOT(connected()));
    QObject::connect(sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    
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
    sendCommand("name");

//    ticktimer->start(100);
}

void hhc_n8i8op_device::ticktimeout()
{
    tcnt++;
    tcnt=tcnt%out_buffer.count();
    sendCommand(out_buffer.at(tcnt));
}

void hhc_n8i8op_device::disconnected()
{
    _named = false;
}

void hhc_n8i8op_device::setRelays(QString ascii_command)
{
}

void hhc_n8i8op_device::connectToRealDevice()
{
    bool ok;
    if (sock->state() != QAbstractSocket::ConnectedState)
    {
        sock->connectToHost(_host, _port.toInt(&ok));
    }
}

void hhc_n8i8op_device::sendCommand(QString cmd)
{
    qDebug() << "SEND: #" << cmd.toLocal8Bit() << "#";
    sock->write(cmd.toLocal8Bit());
    sock->flush();
}

void hhc_n8i8op_device::readyRead()
{
    qDebug() << " ----------------- READYREAD -------------------------- " << _name;
    in_buffer+=QString(sock->readAll());
    qDebug() << in_buffer;

    // We do not expect the device to change its name frequently, thus the name is handled differently
    // outside of the frequently used other replays. Upon connection, we query the name of the device, 
    // then set _named to true, so it is not considered anymore. It also keeps the regexp a bit simpler.

    if (!_named)
    {
        int s = in_buffer.indexOf("name");
        int e = in_buffer.lastIndexOf("\"");
        QString rname = in_buffer.mid(s, e - s);
        rname = rname.replace("name=", "");
        rname = rname.replace("\"", "");
        _name = rname;
        _named = true;
        in_buffer = in_buffer.mid(0, s) + in_buffer.mid(e+1);
        qDebug() << "MODBUFFER:" << in_buffer << "#";
        qDebug() << "NAME:" << _name;
    }
    
    // There are 2 constrainst here: the device is always sending complete ASCII commands, thus we should not
    // expect incoming data to be in intermediate transmission state. Second, the device tends to prell, so
    // we need to debounce it on software side. It means, that when a prelled transmission is coming, we drop
    // ALL of the incoming commands, expect the last one.

    // According to HHC-N8I8OP documentation, the following commands could be sent from the device (the 000.. 
    // represens 0 or 1 values in ASCII string. 
    // 
    // - input00000000 - the device send all input port status. It is transmitted after "input" is send from
    //                   HyperBorg node, or the device transfers it if it is in "triggered" mode
    // - relay00000000 - the device sends this after the "read" or "all" command is sent to it. It is not generated
    //                   automatically.
    // - on0           - device sends relay port status after a command "on<port>:<timeout> is sent, or the
    //                   relay is set be the "on" command
    // - off0          - device sends relay port status after the command "off0" issued to it
    // - name = "xxx"  - device returns its preset name (configurable by its tool) after "name" command is issued

    QStringList rawlist = in_buffer.split(readregexp);
    for (int i = 0; i < rawlist.count(); i++)
    {
        qDebug() << i << " " << rawlist.at(i);
    }
    in_buffer = "";

    // Some more constrains here: the "input" is bounced due to the physical implementation of the device, so that should
    // be debounced before further processing. All the other types of reply should be orderly collected and
    // sent for further execution. The HyperBorg driver does not expect to send commands grouped so the reply
    // is collected in one line.

    QString input_str;

    for (int i = 0; i < rawlist.count()-1; i += 2)
    {
        QString cmd = rawlist.at(i);
        QString val = rawlist.at(i + 1);
        if (cmd == "input")
        {
            if (val.length() == 8)
            {
                input_str = val;
            }
        }
        else if (cmd == "relay")
        {
            if (val.length() == 8)
            {

            }
        }
    }

    // Since the control part is not yet implemented in the whole project, this device is 
    // fixed to bypass mode. Thus if any of the input is changing, the corresponding relay is set
    // to it after debouncing the signal. 

    if (_bypass)
    {
        if (!input_str.isEmpty())
        {
            sendCommandDelayed("all" + input_str);
        }
    }
}

