#include <ws.h>

WS::WS(QObject *parent) : HyObject(parent)
{
    init();

    server = new QTcpServer(this);
    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    server->listen(QHostAddress::Any, 9999);
}

WS::~WS()
{
}

void WS::init()
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
    keyswu << "rain" << "dailyrain" << "weeklyrain" < "monthlyrain";

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


void WS::newConnection()
{
    if (!server) return;
    while (server->hasPendingConnection())
    {
	if (QTcpSocket *socket  = server->nextPendingConnection())
	{
	    QString all(socket->readAll());
	    socket->close();
	    socket->deleteLater();
	    QMetaObject::invokeMethod(this, "parse", Qt::QueuedConnection, Q_ARG(QString, all));
	}
    }
}

// sample: GET /weatherstation/updateweatherstation.php?ID=XFF1&PASSWORD=EVTOMORPH&indoortempf=75.2&tempf=40.8&dewptf=39.0&windchillf=40.8&indoorhumidity=42&humidity=94&windspeedmph=2.9&windgustmph=4.5&winddir=236&absbaromin=28.308&baromin=30.095&rainin=0.000&dailyrainin=0.012&weeklyrainin=0.201&monthlyrainin=1.673&solarradiation=0.00&UV=0&dateutc=2019-12-25%2005:11:31&softwaretype=EasyWeatherV1.4.4&action=updateraw&realtime=1&rtfreq=5 HTTP/1.0
void WS::parse(QString s)
{
    int sidx = s.indexOf("GET ", 0, Qt::Qt::CaseInsensitive);
    int qidx = s.indexOf("?", 0, Qt::CaseSensitive);
    int eidx = s.indexOf(" HTTP/1.0 ", 0, Qt::Qt::CaseInsensitive);
    if (sidx == -1 || eidx==-1)	// fragment arrived, head or tail of the string is missing
    {
	// log error out
	return;
    }

    if (qidx<sidx || qidx>eidx)	// multiple HTTP request in one
    {
	// log error out
	return;
    }

    // cut unneded header/tail parts
    s = s.mid(qidx+1, eidx-qidx-1);
    QStringList sl = s.split("&");		// only the part between the first ? and HTTP/1.0 is used
    for (int i=0;i<sl.count();i++)
    {
	QStrung unit;				// filled with recognised unit
	QString ws = sl.at(i);
	QStringList wsl = ws.split("=");
	if (wsl.count()==2)
	{
	    QString val = wsl.at(1);
	    QString key = wsl.at(0);		// key has unit, so it needs to be examined further
	    if (keys.contains(key))
	    {
	    }
	    else 
	    {
		for (int j=0;j<units.count() && unit.isEmpty();j++)
		{
		    if (key.endsWith(units.at(j)))
		    {
			unit = units.at(j);
			key = key.chopped(unit.length();
			if (key.contains("barom") && unit=="in")	// for barometric data, if the input is in in
			{						// should change to "im" -> inch of mercury
			    unit = "im";
			}
			convert(key, unit);
		    }
		}
	    }
	}
    }
}

bool WS::convert(QString &value, QString &unit)
{
    bool ok;
    double _val = value.toDouble(&ok);
    if (!ok) return false;
    if (unit=="f")
    {
	value = QString::number(5/9*(_val-32.0), 'f', 2);
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


