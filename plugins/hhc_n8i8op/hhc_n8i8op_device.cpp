#include <hhc_n8i8op_device.h>

hhc_n8i8op_device::hhc_n8i8op_device(QObject *parent) : HDevice(parent), sock(NULL), tcnt(0), send_ack(1), _initialized(false)
{
    _test = false;
    _named = false;
    readregexp = QRegularExpression("(?i)((?<=[A-Z])(?=\\d))|((?<=\\d)(?=[A-Z]))");

    maxports = 8;
    for (int i=0;i<maxports;i++)
    {
	ports.append(new HHCN8I8OPDevicePort());
    }

    QObject::connect(&reconnect_timer, SIGNAL(timeout()), this, SLOT(connectToRealDevice()));
    reconnect_timer.setSingleShot(false);
 
    QObject::connect(&pingtimer, SIGNAL(timeout()), this, SLOT(checkPingStatus()));
    pingtimer.setSingleShot(false);
    pingtimer.start(2*60*1000);        

    QObject::connect(&updatetimer, SIGNAL(timeout()), this, SLOT(updateDevice()));
    updatetimer.setSingleShot(true);

    QObject::connect(&testtimer, SIGNAL(timeout()), this, SLOT(test()));
    testtimer.setSingleShot(false);
    testtimer.start(15*1000);
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
    return true;
}

bool hhc_n8i8op_device::loadConfiguration(QString name, QString id, QString host, QString port)
{
    _name = name;
    _id = id;
    _host = host;
    _port = port;
    
    qDebug() << "N8I8OP device direct configuration";
    qDebug() << "	name: " << _name;
    qDebug() << "	id  : " << _id;
    qDebug() << "	host: " << _host;
    qDebug() << "	port: " << _port;

    // TODO:
    // devices should be set for HFS 



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

    // setting up HFS entites 

    if (_id.isEmpty())
    {
        log(0, name + tr("cannot be initialized, since its id is not defined!"));
        return;
    }
    for (int i = 0; i < 8; ++i)
    {
        hfs->provides("switch." + _id + "_" + QString::number(i));
        hfs->provides("button." + _id + "_" + QString::number(i));
    }
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
    if (idx<0 || idx>=maxports) return retint;
    bool ov = ports.at(idx)->input_state;	// old state 
    bool nv = (val);				// new state
    epoch_dt = QDateTime::currentDateTime();

    qint64  ce = epoch_dt.toMSecsSinceEpoch();
    if (ce-ports.at(idx)->last_input_statechange>100)
    {
	if (ports.at(idx)->impulsed)
	{
	    if (nv)		// only 0-1 transition triggers relay switching
	    {
		ov=!ov;
	        ports.at(idx)->input_state = ov;
		ports.at(idx)->last_input_statechange = ce;
    	        ++retint;
		qDebug() << idx << " has state " << ov;
	    }
	}
	else			// for non-impulsed switch, the input and relays should be in sync
	{
	    if (ov!=nv)
	    {   
	        ports.at(idx)->input_state = nv;
	        ++retint;
	    }
	}
    } 
    return retint;
}

void hhc_n8i8op_device::setInputs(QString ascii_command)
{
//    qDebug() << "setInputs: " << ascii_command;
    int ccnt = 0;	// number of relay changed
    for (int i=0;i<qMin(maxports, ascii_command.length());i++)
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
        updatetimer.start(150);  // This has a small delay effect. Buggy switches could generate multiple changes in one run, that would generate a lot of sendMessage
                                // forcing the actual relay hardware to stop responding. This small timer collects all deviceupdate request in the 10 ms range,
                                // thus dispatcing only the last state in the given timeframe.
    }
}

void hhc_n8i8op_device::test()
{
    for (int i=0;i<maxports;++i)
    {
	setRelay(i, _test);
    }
    _test = !_test;
    updateDevice();
}


int hhc_n8i8op_device::setRelay(int idx, int val)
{
    int retint = 0;
    bool bval = (bool)val;
    if (idx>=0 && idx<maxports)
    {
	if (ports.at(idx)->relay_state!=bval)
	{
	    ports.at(idx)->relay_state = bval;
	    retint++;
	}
    }
    return retint;
}

void hhc_n8i8op_device::setRelays(QString ascii_command)
{
    qDebug() << "setRelays: " << ascii_command;
    int cc = 0;
    for (int i=0;i<qMin(maxports, ascii_command.length());i++)
    {
	    QString v = ascii_command.mid(i,1);
	    bool ok;
	    cc+=setRelay(i, v.toInt(&ok));
    }

    if (cc)
	updateDevice();
}

void hhc_n8i8op_device::updateDevice()
{
    QString cmd = "all";
    for (int i=0;i<maxports;i++)
    {
        cmd+=ports.at(i)->relay_state?"1":"0";
    }
    sendCommand(cmd);
}


void hhc_n8i8op_device::connected()
{
    printf("NBI8OP::connected\n");
    sendCommand("name");	// These 3 commands get current status from the device
    sendCommand("read");   	// Order is important! Non impulsed switches could alter
    sendCommand("input");	// the current relay states after power failure!
//    sendCommand("all00000000");
    sendCommand("all00000000");
//   sendCommand("all11111111");
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
    qDebug() << "IN_BUFFER: " << in_buffer;
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

    // in_buffer="input00000000input00000001input00000000input00000001input00000000input00000001input00000000input00000001input00000000heartbeartforrelay2000000";

    QStringList rawlist = in_buffer.split(readregexp);

//    qDebug() << "RAWLIST: " << rawlist;
    in_buffer = "";

    // Some more constrains here: the "input" is bounced due to the physical implementation of the device, so that should
    // be debounced before further processing. All the other types of reply should be orderly collected and
    // sent for further execution. The HyperBorg driver does not expect to send commands grouped so the reply
    // is collected in one line.

    int incomplete = 0;
    int rlc = rawlist.count();
    QString cmd, val;
    bool iscmd = false;

    for (int i=0;i<rlc;++i)
    {
	QString wstr = rawlist.at(i);
	if (wstr=="input" || wstr=="relay" || wstr=="name")
	{	
	    cmd = wstr;
	    val = "";
	}
	else
	{
	    val = wstr;
	}

	if (!cmd.isEmpty() && !val.isEmpty())
	{
	    if (cmd=="input")
	    {
		setInputs(val);
	    }
	    else if (cmd=="relay")
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

    send_ack = 1;       // Emptying send queue
    sendCommand();
}

