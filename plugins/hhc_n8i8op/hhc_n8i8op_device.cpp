#include "hhc_n8i8op_device.h"
#include "../../node/job.h"

hhc_n8i8op_device::hhc_n8i8op_device(QObject* parent)
    : QObject(parent), sock(nullptr), tcnt(0), send_ack(1), _testcnt(0), _test(false), readregexp("(?i)((?<=[A-Z])(?=\\d))|((?<=\\d)(?=[A-Z]))"), maxports(8)
{
    _testcnt = 0;
    _test = false;
    readregexp = QRegularExpression("(?i)((?<=[A-Z])(?=\\d))|((?<=\\d)(?=[A-Z]))");

    maxports = 8;
    for (int i = 0; i < maxports; i++)
    {
        in_ports.prepend(new HHCN8I8OPDevicePort(QString::number(i + 1)));
        relays.prepend(new HHCN8I8OPDevicePort(QString::number(i + 1)));
    }

    connect(&reconnect_timer, &QTimer::timeout, this, &hhc_n8i8op_device::checkConnectionStatus);
    reconnect_timer.setSingleShot(false);
}

hhc_n8i8op_device::~hhc_n8i8op_device()
{
    qDeleteAll(in_ports);
    qDeleteAll(relays);
}

bool hhc_n8i8op_device::loadConfiguration(const QString& name, const QString& id, const QString& host, const QString& port, int expected_heartbeat)
{
    _name = name;
    _id = id;
    _host = host;
    _port = port;
    _expected_heartbeat = expected_heartbeat;

    QMetaObject::invokeMethod(this, "connectToRealDevice", Qt::QueuedConnection);
    _reconnect_timeout = _expected_heartbeat == 0 ? 15 : _expected_heartbeat / 2;
    reconnect_timer.start(_reconnect_timeout);
    return true;
}

void hhc_n8i8op_device::loadConfiguration(const QString& str)
{
    /*
        if (sock)
        {
            sock->disconnect();
            sock->deleteLater();
            sock = nullptr;
        }
        sock = new TcpSocket(this);
        connect(sock, &QTcpSocket::readyRead, this, &hhc_n8i8op_device::readyRead);
        connect(sock, &QTcpSocket::connected, this, &hhc_n8i8op_device::connected);
        connect(sock, &QTcpSocket::disconnected, this, &hhc_n8i8op_device::disconnected);
        connect(sock, &QTcpSocket::stateChanged, this, &hhc_n8i8op_device::stateChanged);

        if (_id.isEmpty())
        {
            log(Info, name + tr("cannot be initialized, since its id is not defined!"));
            return;
        }
        for (int i = 0; i < 8; ++i)
        {
            QString button_topic = "button." + _id + "_" + in_ports.at(i)->devidx;
            hfs->provides(this, button_topic);
            in_ports.at(i)->topic = button_topic;

            QString relay_topic = "relay." + _id + "_" + relays.at(i)->devidx;
            relays.at(i)->topic = relay_topic;
            hfs->provides(this, relay_topic, HFS_GlobalUsage);
            hfs->provides(this, relay_topic + ".turnOn()", HFS_GlobalUsage);
            hfs->provides(this, relay_topic + ".turnOff()", HFS_GlobalUsage);
            hfs->provides(this, relay_topic + ".toggle()", HFS_GlobalUsage);
        }

        keywords.clear();
        keywords << "input" << "relay" << "name" << "on" << "off" << "heartbeat";
    */
}

void hhc_n8i8op_device::setInputs(const QString& ascii_command)
{
    /*
        epoch_dt = QDateTime::currentDateTime();
        qint64  ce = epoch_dt.toMSecsSinceEpoch();

        for (int i = 0; i < in_ports.count() && i < ascii_command.length(); i++)
        {
            HHCN8I8OPDevicePort* port = in_ports.at(i);
            int nval = (ascii_command.mid(i, 1) == "1") ? 1 : 0;

            int cc = 0;
            if (port->impulsed)
            {
                if (nval)       // impulse triggers on value==1
                {
                    if (ce - port->last_statechange > 1000)
                    {
                        port->last_statechange = ce;
                        cc++;
                    }
                }
            }
            else
            {
                if (ce - port->last_statechange > 200)
                {
                    if (port->state != nval)
                    {
                        port->last_statechange = ce;
                        cc++;
                    }
                }
            }

            if (cc)
            {
                port->state = nval;
                hfs->dataChangeRequest(this, "", port->topic, port->state);
            }
        }
    */
}

QVariant hhc_n8i8op_device::turnOn(Job* job)
{
    /*
        qDebug() << "N8I8OP TURNON " << job;
        QString cturl = job->currentTask() ? job->currentTask()->pathTopic() : "";
        if (cturl.isEmpty()) return 0;

        bool found = false;
        for (int i = 0; i < relays.count() && !found; ++i)
        {
            HHCN8I8OPDevicePort* relay = relays.at(i);
            if (relay->topic == cturl)
            {
                found = true;
                relay->state = 0; // Should assert this value to find out if anything else changes the relay state from 3rd party source
                setPhysicalRelay(relay, 1);
            }
        }
    */
    return 0;
}

QVariant hhc_n8i8op_device::turnOff(Job* job)
{
    /*
        qDebug() << "N8I8OP TURNOFF " << job;
        QString cturl = job->currentTask() ? job->currentTask()->pathTopic() : "";
        if (cturl.isEmpty()) return 0;

        bool found = false;
        for (int i = 0; i < relays.count() && !found; ++i)
        {
            HHCN8I8OPDevicePort* relay = relays.at(i);
            if (relay->topic == cturl)
            {
                found = true;
                relay->state = 1; // Should assert this value to find out if anything else changes the relay state from 3rd party source
                setPhysicalRelay(relay, 0);
            }
        }
        */
    return 0;
}

QVariant hhc_n8i8op_device::toggle(Job* job)                               // Toggle is called from HFS direction, thus we need
{                                                                      // to instruct the relay board to change the relay's state
    /*
    qDebug() << "N8I8OP TOGGLE " << job;
    QString cturl = job->currentTask() ? job->currentTask()->pathTopic() : "";
    if (cturl.isEmpty()) return 0;

    bool found = false;                                                                     // We should not set the relay state in HFS since we are not
    for (int i = 0; i < relays.count() && !found; ++i)
    {
        HHCN8I8OPDevicePort* relay = relays.at(i);
        if (relay->topic == cturl)
        {
            found = true;
            setPhysicalRelay(relay, !relay->state);
        }
    }
*/
    return 0;
}

void hhc_n8i8op_device::setPhysicalRelay(HHCN8I8OPDevicePort* relay, int expected_value)
{
    /*
        if (!relay) return;
        if (expected_value != relay->state)
        {
            QString cmd = expected_value ? "on" : "off";
            cmd += relay->devidx;
            sendCommand(cmd);
            sendCommand("read");                                                // request the actual physical relay states from the device
        }
    */
}

void hhc_n8i8op_device::setRelays(const QString &ascii_command)                        // This is called from the TCP/IP socket, thus the physical relays
{                                                                               // are already set according to ascii_command
/*
    qDebug() << "setRelays: " << ascii_command;                                 // Here we need to only relay :) the state of the actual physical relay

    for (int i = 0; i < relays.count() && i < ascii_command.length(); ++i)
    {
        HHCN8I8OPDevicePort* relay = relays.at(i);
        int nval = (ascii_command.mid(i, 1) == "1") ? 1 : 0;
        if (relay->state != nval)
        {
            relay->state = nval;
            hfs->dataChangeRequest(this, "", relay->topic, nval);
        }
    }
*/
}

void hhc_n8i8op_device::connected()
{
    //NI!log(Info, "N8I8OP device connected");
    sendCommand("name");    // These 3 commands get current status from the device
    sendCommand("read");    // Order is important! Non impulsed switches could alter
    sendCommand("input");   // the current relay states after power failure!
    heartbeat_elapsed.restart();
}

void hhc_n8i8op_device::disconnected()
{
    // Log disconnection
    name.clear();
}

void hhc_n8i8op_device::stateChanged(QAbstractSocket::SocketState socketState)
{
    //NI! log(Info, QString("N8I8OP device at host %1:%2 changed state to %3").arg(_host).arg(_port).arg(socketState));
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        reconnect_timer.start(_reconnect_timeout);
    }
    else
    {
        reconnect_timer.start(15 * 1000); // Reconnection is tried every 15 seconds
    }
}

void hhc_n8i8op_device::checkConnectionStatus()
{
    if ((sock->state() != QAbstractSocket::ConnectedState) || (_expected_heartbeat != 0 && _expected_heartbeat + 3 < heartbeat_elapsed.elapsed()))
    {
        connectToRealDevice();
    }
    else
    {
        sendCommand("name");
    }
}

bool hhc_n8i8op_device::connectToRealDevice()
{
    bool ok;
    if (sock && sock->state() != QAbstractSocket::ConnectedState)
    {
        sock->close();
        sock->connectToHost(_host, _port.toInt(&ok));
        return true;
    }
    return false;
}

void hhc_n8i8op_device::sendCommand(const QString& cmd)
{
    if (!cmd.isEmpty())
    {
        send_queue.append(cmd);
    }

    if (send_ack && !send_queue.isEmpty())
    {
        send_ack = 0;
        QString command = send_queue.takeFirst();
        sock->write(command.toLocal8Bit());
        qDebug() << " <-- " << command.toLocal8Bit();
        sock->flush();
    }
}

void hhc_n8i8op_device::readyRead()
{
    in_buffer += QString(sock->readAll());
    QDateTime ddt = QDateTime::currentDateTime();
    qDebug() << "[" << ddt.toString("yy-MM-dd hh:mm:ss.zzz") << "] INBUFFER: " << in_buffer;

    // Any communication resets the heartbeat watchdog
    heartbeat_elapsed.restart();
    send_ack = 1;

    // Clearing line endings
    in_buffer = in_buffer.replace("\n", "");

    // Extracting name 
    int ns = in_buffer.indexOf("name=\"");
    if (ns > -1)
    {
        int ne = in_buffer.indexOf("\"", ns + 6);
        if (ns != -1 && ne != -1)
        {
            name = in_buffer.mid(ns + 6, ne - ns - 6);
            in_buffer = in_buffer.mid(0, ns) + in_buffer.mid(ne + 1);
        }
    }

    if (in_buffer.isEmpty())
    {
        sendCommand();
        return;
    }

    // Process incoming commands
    processIncomingCommands();

    // Since the control part is not yet implemented in the whole project, this device is
    // fixed to bypass mode. Thus if any of the input is changing, the corresponding relay is set
    // to it after debouncing the signal.

    sendCommand();
}

void hhc_n8i8op_device::processIncomingCommands()
{
    QStringList rawlist = in_buffer.split(readregexp);
    in_buffer.clear();

    int rlc = rawlist.count();
    qDebug() << "RLC: " << rlc << "  RAWLST: " << rawlist;
    QString cmd, val;
    bool iscmd = false;

    for (int i = 0; i < rlc; ++i)
    {
        bool skipval = false;
        QString wstr = rawlist.at(i);
        if (keywords.contains(wstr))
        {
            cmd = wstr;
            val.clear();
            if (wstr == "heartbeat")
                skipval = true;
        }
        else
        {
            val = wstr;
        }

        if (skipval || (!cmd.isEmpty() && !val.isEmpty()))
        {
            if (cmd == "input")
            {
                setInputs(val);
            }
            else if (cmd == "relay")
            {
                setRelays(val);
            }
            cmd.clear();
            val.clear();
        }
    }
}