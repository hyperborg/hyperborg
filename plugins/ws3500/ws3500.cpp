#include <ws3500.h>

ws3500::ws3500(QObject *parent) : HyObject(parent)
{
    server = new QTcpServer(this);
    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    server->listen(QHostAddress::Any, 33336);
}

ws3500::~ws3500()
{
}

void ws3500::newConnection()
{
    if (!server) return;
    while (server->hasPendingConnections())
    {
	    if (QTcpSocket *socket  = server->nextPendingConnection())
	    {
	        QString all(socket->readAll());
	        sockets.append(socket);
	        QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
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

void ws3500::init()
{
    qDebug() << "WS3500 init with HFS: " << hfs;
    _pathbase="sensors.ws3500.";

    // simple keys
    keys << "ID" << "PASSWORD";

    keys << "indoorhumidity" << "humidity";
    keys << "winddir";
    keys << "solarradiation" << "UV";
    keys << "dateutc" << "softwaretype";
    keys << "realtime";
    keys << "rtfreq";

    // keys expected to have unit concatenated
    keyswu << "dewpt" << "windchill";
    keyswu << "indoortemp" << "temp";
    keyswu << "windspeed" << "windgust";
    keyswu << "absbarom" << "barom";
    keyswu << "rain" << "dailyrain" << "weeklyrain" << "monthlyrain";

    units << "c" << "f" << "mm" << "in" << "kmh" << "mph";
    postfixs << "_C" << "_F" << "_mm" << "_inch" << "_KMH" << "_MPH";
    hunits << Celsius << Farenheit << Milimeter << Inch << Kmh << Mph;

    hfs->providesSensor(this, _pathbase+"indoortemp_F",         DT_Float,   Farenheit);
    hfs->providesSensor(this, _pathbase+"indoortemp_C",         DT_Float,   Celsius);
    hfs->providesSensor(this, _pathbase+"temp_F",               DT_Float,   Farenheit);
    hfs->providesSensor(this, _pathbase+"temp_C",               DT_Float,   Celsius);
    hfs->providesSensor(this, _pathbase+"dewpt_F",              DT_Float,   Farenheit);
    hfs->providesSensor(this, _pathbase+"dewpt_C",              DT_Float,   Celsius);
    hfs->providesSensor(this, _pathbase+"windchill_F",          DT_Float,   Farenheit);
    hfs->providesSensor(this, _pathbase+"windchill_C",          DT_Float,   Celsius);
    hfs->providesSensor(this, _pathbase+"windspeed_MPH",        DT_Float,   Mph);
    hfs->providesSensor(this, _pathbase+"windspeed_KMH",        DT_Float,   Kmh);
    hfs->providesSensor(this, _pathbase+"windgust_MPH",         DT_Float,   Mph);
    hfs->providesSensor(this, _pathbase+"windgust_KMH",         DT_Float,   Kmh);

    hfs->providesSensor(this, _pathbase+"absbarom_InHg",        DT_Float,   InHg);
    hfs->providesSensor(this, _pathbase+"barom_InHg",           DT_Float,   InHg);
    hfs->providesSensor(this, _pathbase+"absbarom_HgMM",        DT_Float,   HgMM);
    hfs->providesSensor(this, _pathbase+"barom_HgMM",           DT_Float,   HgMM);
    hfs->providesSensor(this, _pathbase+"absbarom_HPa",         DT_Float,   hPa);
    hfs->providesSensor(this, _pathbase+"barom_HPa",            DT_Float,   hPa);

    hfs->providesSensor(this, _pathbase+"rain_inch",            DT_Float,   Inch);
    hfs->providesSensor(this, _pathbase+"dailyrain_inch",       DT_Float,   Inch);
    hfs->providesSensor(this, _pathbase+"weeklyrain_inch",      DT_Float,   Inch);
    hfs->providesSensor(this, _pathbase+"monthlyrain_inch",     DT_Float,   Inch);
    hfs->providesSensor(this, _pathbase+"rain_mm",              DT_Float,   Milimeter);
    hfs->providesSensor(this, _pathbase+"dailyrain_mm",         DT_Float,   Milimeter);
    hfs->providesSensor(this, _pathbase+"weeklyrain_mm",        DT_Float,   Milimeter);
    hfs->providesSensor(this, _pathbase+"monthlyrain_mm",       DT_Float,   Milimeter);

    hfs->providesSensor(this, _pathbase+"winddir",              DT_Integer, Compass);
    hfs->providesSensor(this, _pathbase+"indoorhumidity",       DT_Float,   Percent);
    hfs->providesSensor(this, _pathbase+"humidity",             DT_Float,   Percent);
    hfs->providesSensor(this, _pathbase+"solarradiation",       DT_Float,   Wm2);
    hfs->providesSensor(this, _pathbase+"UV",                   DT_Integer, Level);
    hfs->providesSensor(this, _pathbase+"dateutc",              DT_String,  String);
    hfs->providesSensor(this, _pathbase+"softwaretype",         DT_String,  String);

}

/* Note on accepting and parsing connection: The weatherstation does sends all of its data as a GET frame.
Here we do not want to create too much fuss about it, there is no need for full HTTP header parsing and so.
We look for what we expect. If that fits, we parse, if not we log that and discard. This way we can keep
this module small and simple.

Communication wise, we do not keep the TCP/IP connection open and expect to have a full header in a new 
connection. 
*/

// sample: "GET /wetterstation.php?ID=123&PASSWORD=123&indoortempf=77.7&tempf=76.6&dewptf=59.4&windchillf=76.6&indoorhumidity=51&humidity=55&windspeedmph=0.0&windgustmph=0.0&winddir=3&absbaromin=29.407&baromin=29.977&rainin=0.000&dailyrainin=0.000&weeklyrainin=0.000&monthlyrainin=0.000&solarradiation=0.00&UV=0&dateutc=2021-08-24%2019:28:54&softwaretype=EasyWeatherV1.5.9&action=updateraw&realtime=1&rtfreq=5 HTTP/1.0\r\nHost: 192.168.37.27\r\nAccept:*/*\r\nConnection: Close\r\n\r\n"

void ws3500::parse(QString s)
{
    qDebug() << s ;
    int sidx = s.indexOf("GET ", 0, Qt::CaseInsensitive);
    int qidx = s.indexOf("?", 0, Qt::CaseSensitive);
    int eidx = s.indexOf(" HTTP/", 0, Qt::CaseInsensitive);
    if (sidx == -1 || eidx==-1)	// fragment arrived, head or tail of the string is missing
    {
	    log(Info, "Fragment arrived, bail out");
	    return;
    }

    if (qidx<sidx || qidx>eidx)	// multiple HTTP request in one
    {
	    log(Info, "Multiple GET in report");
	    return;
    }

    // cut unneded header/tail parts
    s = s.mid(qidx+1, eidx-qidx-1);
    QStringList sl = s.split("&");		// only the part between the first ? and HTTP/1.0 is used
                                        // prescanning for id & password, required for authentication and Entity existence 
                                        // check
    QString _id;
    QString _passwd;
    for (int i = 0; i < sl.count() && _id.isEmpty() && _passwd.isEmpty(); i++)
    {
        QString key; 
        QString val;
        if (splitKeyAndVal(sl.at(i), key, val))
        {
            if (key.toUpper()=="ID")                _id = val;
            else if (key.toUpper()=="PASSWORD")     _passwd = val;    
        }
    }

    if (_id.isEmpty()) return;              // WU protocol expect ID to be filled out
    if (!checkAccess(_id, _passwd)) return; // should validate source against some local auth database

    startModification(name());

    for (int i=0;i<sl.count();i++)
    {
        QString unit;               // filled with recognised unit
        QString ws = sl.at(i);
        QString key;
        QString val;
        if (splitKeyAndVal(ws, key, val))
        {
            if (keys.contains(key))                     // The simple fields without units
            {
                if (key.toUpper() == "ID") _id = val;
            }
            else
            {
/*
// sample: "GET /wetterstation.php?ID=123&PASSWORD=123&
indoortempf=77.7&
tempf=76.6&
dewptf=59.4&
windchillf=76.6
indoorhumidity=51
humidity=55
windspeedmph=0.0
windgustmph=0.0
winddir=3
absbaromin
29.407
baromin=29.977
rainin=0.000
dailyrainin=0.000
weeklyrainin=0.000
monthlyrainin=0.000
solarradiation=0.00
UV=0
*/
                for (int j = 0; j < units.count() && unit.isEmpty(); j++)
                {
                    if (key.endsWith(units.at(j)))
                    {
                        unit = units.at(j);
                        Unit hunit = hunits.at(j);
                        key = key.chopped(unit.length());
                        if (key.contains("barom") && unit == "in")  // for barometric data, if the input is in in
                        {                                           // should change to "im" -> inch of mercury
                            unit = "im";
                            hunit = InHg;
                        }

//    units << "c" << "f" << "cm" << "in" << "kmh" << "mph";
//    hunits << Celsius << Farenheit << Centimeter << Inch << Kmh << Mph;


                        if (hunit!=InHg)
                        {
                            if (j%2==0)    // Metric unit found in input
                            {
                                hfs->dataChangeRequest(_pathbase+key+postfixs.at(j), val);
                                hfs->dataChangeRequest(_pathbase+key+postfixs.at(j+1), hround(convert(hunits.at(j),hunits.at(j+1),val.toDouble()),2));
                            }
                            else        // Imperial unit found
                            {
                                hfs->dataChangeRequest(_pathbase+key+postfixs.at(j), val);
                                hfs->dataChangeRequest(_pathbase+key+postfixs.at(j-1), hround(convert(hunits.at(j),hunits.at(j-1),val.toDouble()),2));
                            }
                        }
                        else    // Barometric values handled differently
                        {
                            double baseHPa = convert(InHg, hPa, val.toDouble());
                            hfs->dataChangeRequest(_pathbase+key+"_InHg", hround(convert(hPa, InHg, baseHPa),3));
                            hfs->dataChangeRequest(_pathbase+key+"_HPa",  hround(baseHPa,3));
                            hfs->dataChangeRequest(_pathbase+key+"_HgMM", hround(convert(hPa, HgMM, baseHPa),3));
                        }
                    }
                }
            }
            //NI!! setValue(key, HyValue(QVariant(val), Unit::Any), name());
        }
    }
    endModification(name()); 
}

bool ws3500::splitKeyAndVal(QString src, QString& key, QString& val)
{
    QStringList wsl = src.split("=");
    if (wsl.count() == 2)
    {
        key = wsl.at(0);
        val = wsl.at(1);
        return true;
    }
    return false;
}

bool ws3500::checkAccess(QString id, QString passwd)
{
    // At this moment we allow all ws access
    return true;
}

