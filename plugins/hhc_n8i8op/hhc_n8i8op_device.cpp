#include <hhc_n8i8op_device.h>
#include "../../node/job.h"

hhc_n8i8op_device::hhc_n8i8op_device(QObject* parent) : QObject(parent), sock(nullptr), tcnt(0), send_ack(1)
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

    QObject::connect(&reconnect_timer, SIGNAL(timeout()), this, SLOT(checkConnectionStatus()));
    reconnect_timer.setSingleShot(false);
}

hhc_n8i8op_device::~hhc_n8i8op_device()
{
    for (int i = 0; i < in_ports.count(); i++)
        delete in_ports.at(i);
    for (int i = 0; i < relays.count(); i++)
        delete relays.at(i);
}

bool hhc_n8i8op_device::loadConfiguration(QString name, QString id, QString host, QString port, int expected_heartbeat)
{
    _name = name;
    _id = id;
    _host = host;
    _port = port;
    _expected_heartbeat = expected_heartbeat;;

/*NI!
    log(Info, "N8I8OP device direct configuration");
    log(Info, QString(" name  : %1").arg(_name));
    log(Info, QString(" id    : %1").arg(_id));
    log(Info, QString(" host  : %1").arg(_host));
    log(Info, QString(" port  : %1").arg(_port));
    log(Info, QString(" hbeat : %1").arg(_expected_heartbeat));
*/

    // TODO:
    // devices should be set for HFS

    QMetaObject::invokeMethod(this, "connectToRealDevice", Qt::QueuedConnection);
    _reconnect_timeout = _expected_heartbeat==0?15:_expected_heartbeat/2;
    reconnect_timer.start(_reconnect_timeout);
    return true;
}

void hhc_n8i8op_device::loadConfiguration(QString str)
{
/*
    if (sock)
    {
        sock->disconnect();
        sock->deleteLater();
        sock = nullptr;
    }
    sock = new TcpSocket(this);
    QObject::connect(sock, SIGNAL(readyRead()), this, SLOT(readyRead()));
    QObject::connect(sock, SIGNAL(connected()), this, SLOT(connected()));
    QObject::connect(sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    QObject::connect(sock, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));

    // setting up HFS entites

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
        hfs->provides(this, relay_topic+".turnOn()", HFS_GlobalUsage);
        hfs->provides(this, relay_topic+".turnOff()", HFS_GlobalUsage);
        hfs->provides(this, relay_topic+".toggle()", HFS_GlobalUsage);
    }

    keywords.clear();
    keywords << "input" << "relay" << "name" << "on" << "off" << "heartbeat";
*/
}

void hhc_n8i8op_device::setInputs(QString ascii_command)
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

QVariant hhc_n8i8op_device::turnOn(Job *job)
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

QVariant hhc_n8i8op_device::turnOff(Job *job)
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

QVariant hhc_n8i8op_device::toggle(Job *job)                               // Toggle is called from HFS direction, thus we need
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

void hhc_n8i8op_device::setRelays(QString ascii_command)                        // This is called from the TCP/IP socket, thus the physical relays
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
    //NI!log(Info, "N8I8OP device disconnected");
    name = QString();
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
        reconnect_timer.start(15*1000);         // Reconnection is tried in every 15 secs
    }
}

void hhc_n8i8op_device::checkConnectionStatus()
{
    if ((sock->state() != QAbstractSocket::ConnectedState) || (_expected_heartbeat!=0 && _expected_heartbeat+3<heartbeat_elapsed.elapsed()))
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

void hhc_n8i8op_device::sendCommand(QString cmd)
{
    if (!cmd.isEmpty())
    {
        send_queue.append(cmd);
    }

    if (send_ack)
    {
        if (!send_queue.isEmpty())
        {
            send_ack = 0;
            cmd = send_queue.takeFirst();
            sock->write(cmd.toLocal8Bit());
            qDebug() << " <-- " << cmd.toLocal8Bit();
            sock->flush();
        }
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
    in_buffer = in_buffer.replace("\n","");

    // Extracting name ie
    int ns = in_buffer.indexOf("name=\"");
    if (ns>-1)
    {
        int ne=in_buffer.indexOf("\"", ns+6);
        if (ns!=-1 && ne!=-1)
        {
            name = in_buffer.mid(ns+6, ne-ns-6);
            in_buffer = in_buffer.mid(0, ns) + in_buffer.mid(ne+1);
        }
    }

    if (in_buffer.length()==0) 
    {
        sendCommand();
        return;
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

    // in_buffer="input00000000input00000001input00000000input00000001input00000000input00000001input00000000input00000001input00000000heartbeartforrelay2000000";

    QStringList rawlist = in_buffer.split(readregexp);

    in_buffer = "";

    // Some more constrains here: the "input" is bounced due to the physical implementation of the device, so that should
    // be debounced before further processing. All the other types of reply should be orderly collected and
    // sent for further execution. The HyperBorg driver does not expect to send commands grouped so the reply
    // is collected in one line.

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
            val = "";
            if (wstr=="heartbeat")
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
            cmd = "";
            val = "";
        }
    }

    // Since the control part is not yet implemented in the whole project, this device is
    // fixed to bypass mode. Thus if any of the input is changing, the corresponding relay is set
    // to it after debouncing the signal.

    sendCommand();
}
