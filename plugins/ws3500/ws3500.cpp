#include <ws3500.h>

ws3500::ws3500(QObject *parent) : HyObject(parent)
{
    init();

    server = new QTcpServer(this);
    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    server->listen(QHostAddress::Any, 33336);
}

ws3500::~ws3500()
{
}

void ws3500::init()
{
    // simple keys
    keys << "ID" << "PASSWORD";
    keys << "dewpt" << "windchill";
    keys << "indoorhumidity" << "humidity";
    keys << "winddir";
    keys << "solarradiation" << "UV";
    keys << "dateutc" << "softwaretype";
    keys << "realtime";
    keys << "rtfreq";

    // keys expected to have unit concatenated
    keyswu << "indoortemp" << "temp";
    keyswu << "windspeed" << "windgust";
    keyswu << "absbarom" << "barom";
    keyswu << "rain" << "dailyrain" << "weeklyrain" << "monthlyrain";

    units << "c" << "f";
    units << "cm" << "in";
    units << "kmh" << "mph";
}

/* Note on accepting and parsing connection: The weatherstation does sends all of its data as a GET frame.
Here we do not want to create too much fuss about it, there is no need for full HTTP header parsing and so.
We look for what we expect. If that fits, we parse, if not we log that and discard. This way we can keep
this module small and simple.

Communication wise, we do not keep the TCP/IP connection open and expect to have a full header in a new 
connection. 
*/

void ws3500::newConnection()
{
    log(0, "WS3500 NEW CONNECTION");
    if (!server) return;
    while (server->hasPendingConnections())
    {
	if (QTcpSocket *socket  = server->nextPendingConnection())
	{
	    QString all(socket->readAll());
	    sockets.append(socket);
	    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
//	    socket->close();
//	    socket->deleteLater();
//	    QMetaObject::invokeMethod(this, "parse", Qt::QueuedConnection, Q_ARG(QString, all));
	}
    }
}

void ws3500::readyRead()
{
    if (QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender()))
    {
    	QString all(socket->readAll());
	socket->close();
	socket->deleteLater();
	sockets.removeAll(socket);
	QMetaObject::invokeMethod(this, "parse", Qt::QueuedConnection, Q_ARG(QString, all));
    }
}

// sample: "GET /wetterstation.php?ID=123&PASSWORD=123&indoortempf=77.7&tempf=76.6&dewptf=59.4&windchillf=76.6&indoorhumidity=51&humidity=55&windspeedmph=0.0&windgustmph=0.0&winddir=3&absbaromin=29.407&baromin=29.977&rainin=0.000&dailyrainin=0.000&weeklyrainin=0.000&monthlyrainin=0.000&solarradiation=0.00&UV=0&dateutc=2021-08-24%2019:28:54&softwaretype=EasyWeatherV1.5.9&action=updateraw&realtime=1&rtfreq=5 HTTP/1.0\r\nHost: 192.168.37.27\r\nAccept:*/*\r\nConnection: Close\r\n\r\n"

void ws3500::parse(QString s)
{
    int sidx = s.indexOf("GET ", 0, Qt::CaseInsensitive);
    int qidx = s.indexOf("?", 0, Qt::CaseSensitive);
    int eidx = s.indexOf(" HTTP/1.0", 0, Qt::CaseInsensitive);
    if (sidx == -1 || eidx==-1)	// fragment arrived, head or tail of the string is missing
    {
	log(0, "Fragment arrived, bail out");
	// log error out
	return;
    }

    if (qidx<sidx || qidx>eidx)	// multiple HTTP request in one
    {
	log(0, "Multiple GET in report");
	// log error out
	return;
    }

    // cut unneded header/tail parts
    s = s.mid(qidx+1, eidx-qidx-1);
    QStringList sl = s.split("&");		// only the part between the first ? and HTTP/1.0 is used
    qDebug() << " ----------- WS3500 -------------------";
    qDebug() << "SL: " << sl;
    QString _id;
    for (int i=0;i<sl.count();i++)
    {
	QString unit;				// filled with recognised unit
	QString ws = sl.at(i);
	QStringList wsl = ws.split("=");
	if (wsl.count()==2)
	{
	    QString val = wsl.at(1);
	    QString key = wsl.at(0);		// key has unit, so it needs to be examined further
	    if (keys.contains(key))
	    {
		if (key.toUpper()=="ID") _id=val;
	    }
	    else 
	    {
		for (int j=0;j<units.count() && unit.isEmpty();j++)
		{
		    if (key.endsWith(units.at(j)))
		    {
			unit = units.at(j);
			key = key.chopped(unit.length());
			if (key.contains("barom") && unit=="in")	// for barometric data, if the input is in in
			{						// should change to "im" -> inch of mercury
			    unit = "im";
			}
			convert(val, unit);
		    }
		}
	    }
	    // process data (key, val, unit)
	    QString id=_id+"_"+key;
	    HEntity *entity = entities[id];
	    if (!entity)
	    {
		entity = he_factory->create(id, this);
		if (entity)
		    entities.insert(id, entity);
	    }
	    if (entity)
	    {
		entity->setValue(val, unit);
	    }
	}
    }
}

bool ws3500::convert(QString &value, QString &unit)
{
    bool ok;
    double _val = value.toDouble(&ok);
    if (!ok) return false;
    if (unit=="f")
    {
	value = QString::number(5.0/9.0*(_val-32.0), 'f', 2);
	unit = "C";
    }
    else if (unit=="in")
    {
	value = QString::number(_val*2.54, 'f', 2);
	unit = "cm";
    }
    else if (unit=="im")
    {
	value = QString::number(_val*33.862, 'f', 2);
	unit = "hPa";
    }
    else if (unit=="mph")
    {
	value = QString::number(_val*1.609344, 'f', 2); 	// international mile
	unit = "kmh";						// C'mon USA, you should really use the metric system! :D
    }								// Gosh! There are 30+ different miles in wiki!
    return true;
}

QJsonObject ws3500::configurationTemplate()
{
    return QJsonObject();
}

void ws3500::saveConfiguration(QJsonObject& json)
{
    Q_UNUSED(json);
}

bool ws3500::loadConfiguration(QJsonObject json)
{
    Q_UNUSED(json);
    return true;
}


