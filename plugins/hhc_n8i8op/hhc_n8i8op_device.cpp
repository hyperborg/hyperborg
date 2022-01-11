#include <hhc_n8i8op_device.h>

hhc_n8i8op_device::hhc_n8i8op_device(QObject *parent) : HDevice(parent), sock(NULL), tcnt(0), send_ack(1), _initialized(false)
{
    _named = false;
    _bypass = true;
    readregexp = QRegularExpression("(?i)((?<=[A-Z])(?=\\d))|((?<=\\d)(?=[A-Z]))");

    QObject::connect(&reconnect_timer, SIGNAL(timeout()), this, SLOT(connectToRealDevice()));
    reconnect_timer.setSingleShot(false);
 
    QObject::connect(&pingtimer, SIGNAL(timeout()), this, SLOT(checkPingStatus()));
    pingtimer.setSingleShot(false);
    pingtimer.start(2*60*1000);        

    QObject::connect(&updatetimer, SIGNAL(timeout()), this, SLOT(updateDevice()));
    updatetimer.setSingleShot(true);
}

hhc_n8i8op_device::~hhc_n8i8op_device()
{
}

QJsonObject hhc_n8i8op_device::configurationTemplate()
{
    QJsonObject obj;
    return obj;
}

bool hhc_n8i8op_device::loadConfiguration(QJsonObject json)
{
    if (json.contains("name") && json["name"].isString())
        _name = json["name"].toString();
    if (json.contains("id") && json["id"].isString())
        _id = json["id"].toString();
    if (json.contains("host") && json["host"].isString())
        _host = json["host"].toString();
    if (json.contains("port") && json["port"].isString())
        _port = json["port"].toString();

    qDebug() << "N8I8OP device configuration";
    qDebug() << "	name: " << _name;
    qDebug() << "	id  : " << _id;
    qDebug() << "	host: " << _host;
    qDebug() << "	port: " << _port;
    QMetaObject::invokeMethod(this, "connectToRealDevice", Qt::QueuedConnection);
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
        sock = NULL;
    }
    sock = new TcpSocket(this);
    QObject::connect(sock, SIGNAL(readyRead()), this, SLOT(readyRead()));
    QObject::connect(sock, SIGNAL(connected()), this, SLOT(connected()));
    QObject::connect(sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    QObject::connect(sock, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
    

    for (int i=0;i<8;i++)
    {
	    entities.append(new BypassEntity());
    }

    entities.at(2)->impulsed = false;   // TEST: in POC, these are fix toggle swithces
    entities.at(3)->impulsed = false;
}

void hhc_n8i8op_device::checkPingStatus()
{
    if (pingelapsed.elapsed() > 3 * 60 * 1000)  // no communication in the last 3 minutes from relay board
    {
        if (sock)
        {
            sock->close();      // disconnect socket and start reconnect session
            reconnect_timer.start(15 * 1000);
        }
    }
}

int hhc_n8i8op_device::setInput(int idx, int val)
{
    int retint = 0;
    if (idx<0 || idx>=entities.count()) return retint;
    bool ov = entities.at(idx)->state;	// old state 
    bool nv = (val);			// new state

    if (entities.at(idx)->impulsed)
    {
        if (nv)		// only 0-1 transition triggers relay switching
	    {
	        ov=!ov;
            if (entities.at(idx)->timer.elapsed() > 400)
            {
                entities.at(idx)->state = ov;
                entities.at(idx)->timer.restart();
                ++retint;
            }
	    }
    }
    else			// for non-impulsed switch, the input and relays should be in sync
    {
	    if (ov!=nv)
	    {   
	        entities.at(idx)->state = nv;
	        ++retint;
	    }
    }
    return retint;
}

void hhc_n8i8op_device::setInputs(QString ascii_command)
{
    int ccnt = 0;	// number of relay changed
    for (int i=0;i<qMin(entities.count(), ascii_command.length());i++)
    {
	    QString v = ascii_command.mid(i,1);
	    bool ok;
   	    int nv = v.toInt(&ok);
	    if (ok)
	    {
		    ccnt+=setInput(i, nv);
	    }
    }
    
    if (ccnt)
    {
        updatetimer.start(20);  // This has a small delay effect. Buggy switches could generate multiple changes in one run, that would generate a lot of sendMessage
                                // forcing the actual relay hardware to stop responding. This small timer collects all deviceupdate request in the 10 ms range,
                                // thus dispatcing only the last state in the given timeframe.
    }
}

void hhc_n8i8op_device::setRelay(int idx, int val)
{
    if (idx>=0 && idx<entities.count())
    {
        entities.at(idx)->state = (bool)val;
    }
}

void hhc_n8i8op_device::setRelays(QString ascii_command)
{
    for (int i=0;i<qMin(entities.count(), ascii_command.length());i++)
    {
	    QString v = ascii_command.mid(i,1);
	    bool ok;
	    setRelay(i, v.toInt(&ok));
    }
}

void hhc_n8i8op_device::updateDevice()
{
    QString cmd = "all";
    for (int i=0;i<entities.count();i++)
    {
	    cmd+=entities.at(i)->state?"1":"0";
    }
    sendCommand(cmd);
}


void hhc_n8i8op_device::connected()
{
    printf("NBI8OP::connected\n");
    sendCommand("name");	// These 3 commands get current status from the device
    sendCommand("read");   	// Order is important! Non impulsed switches could alter
    sendCommand("input");	// the current relay states after power failure!
    reconnect_timer.stop();
    pingelapsed.restart();
}

void hhc_n8i8op_device::disconnected()
{
    _named = false;
    _initialized = false;
}   

void hhc_n8i8op_device::stateChanged(QAbstractSocket::SocketState socketState)
{
    return;
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        reconnect_timer.start(15 * 1000);       // trying to reconnect in 30 secs
    }
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
    if (!cmd.isEmpty())
    {
        send_queue.append(cmd);
    }

    if (send_ack)
    {
        if (!send_queue.isEmpty())
        {
            cmd = send_queue.takeFirst();
            send_ack = 0;
            sock->write(cmd.toLocal8Bit());
            sock->flush();
        }
    }
}

void hhc_n8i8op_device::readyRead()
{
    in_buffer+=QString(sock->readAll());
    pingelapsed.restart();      // incoming data hadled as ping too
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
    }

    // Clearing out embedded PING flag
    if (in_buffer.contains("PING"))
    {
        in_buffer.remove("PING");
        pingelapsed.restart();
    }

    // Clearing line endings 
    in_buffer.remove("\n");
    
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
    in_buffer = "";

    // Some more constrains here: the "input" is bounced due to the physical implementation of the device, so that should
    // be debounced before further processing. All the other types of reply should be orderly collected and
    // sent for further execution. The HyperBorg driver does not expect to send commands grouped so the reply
    // is collected in one line.

    int incomplete = 0;
    int rlc = rawlist.count();
    QString cmd, val;
    for (int i = 0; i < rlc-1; ++i)
    {
        cmd = rawlist.at(i);
        if (i < rlc - 1)                // Cannot be sure that even number of elements are coming
        {                               // Thus, the last element could be a command, not just a parameter
            val = rawlist.at(i + 1);
            i++;
        }
        if (cmd == "input")
        {
	        _initialized = true;
            if (val.length() == 8)
            {
                setInputs(val);
            }
            else if (i > rlc-3)         // we got only command or command + fragmented parameters
            {
                incomplete = 2;
            }
        }
        else if (cmd == "relay")
        {
	        if (!_initialized)
	        {
        	    if (val.length() == 8)
        	    {
            	    setRelays(val);
        	    }
                else if (i > rlc - 3)
                {
                    incomplete = 2;
                }
	        }
        }
        else
        {
            if      (QString("input").startsWith(cmd) && i==rlc-1) incomplete = 2;  // trigger only if last command is truncate
            else if (QString("relay").startsWith(cmd) && i==rlc-1) incomplete = 2;
            else
            {
                i -= 1;     // Skip this unknown command
            }
        }
    }

    switch (incomplete)
    {
        case 1:             // truncated command 
            in_buffer = rawlist.at(rlc-1);
            break;
        case 2:             // truncated parameter <- feed back command and parameter fragment into queue
            in_buffer = rawlist.at(rlc - 2) + rawlist.at(rlc - 1);            
            break;
        case 0:             // Everything is fine and processed nicely
        default:     
            break;
    }

    // Since the control part is not yet implemented in the whole project, this device is 
    // fixed to bypass mode. Thus if any of the input is changing, the corresponding relay is set
    // to it after debouncing the signal. 

    send_ack = 1;       // Emptying send queue
    sendCommand();
}

