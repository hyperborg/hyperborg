#include <ws3500.h>

ws3500::ws3500(QObject *parent) : HyObject(parent), parsecnt(0)
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
    /*
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
    */
}

void ws3500::provideSensors(QStringList lst)
{
/*
    for (int i = 0; i < lst.count(); i++)
    {
        QString key;
        QString val;
        if (splitKeyAndVal(lst.at(i), key, val))
        {
            QString fkey = _pathbase + key;
            if (key == "indoortempf")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Farenheit, "", 2, 2);
                hfs->addDBHook(_pathbase + "indoortemp_F", "sensors");
            }
            else if (key == "tempf")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Farenheit, "", 2, 2);
                hfs->addDBHook(_pathbase + "temp_F", "sensors");
            }
            else if (key == "dewptf")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Farenheit, "", 2, 2);
                hfs->addDBHook(_pathbase + "dewpt_F", "sensors");
            }
            else if (key == "windchillf")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Farenheit, "", 2, 2);
                hfs->addDBHook(_pathbase + "windchill_F", "sensors");
            }
            else if (key == "indoorhumidity")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Percent, "", 1, 2);
                hfs->addDBHook(_pathbase + "indoorhumidity", "sensors");
            }
            else if (key == "humidity")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Percent, "", 1, 2);
                hfs->addDBHook(_pathbase + "humidity", "sensors");
            }
            else if (key == "windspeedmph")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Mph, "", 2, 3);
                hfs->addDBHook(_pathbase + "windspeed_MPH", "sensors");
            }
            else if (key == "windgustmph")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Mph, "", 2, 3);
                hfs->addDBHook(_pathbase + "windgust_MPH", "sensors");
            }
            else if (key == "winddir")
            {
                hfs->providesSensor(this, fkey, DT_Integer, Compass);
                hfs->addDBHook(_pathbase + "winddir", "sensors");
            }
            else if (key == "absbaromin")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, InHg, "", 2, 4);
                hfs->addDBHook(_pathbase + "absbarom_InHg", "sensors");
            }
            else if (key == "baromin")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, InHg, "", 2, 4);
                hfs->addDBHook(_pathbase + "barom_InHg", "sensors");
            }
            else if (key == "rainin")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Inch, "", 2, 2);
                hfs->addDBHook(_pathbase + "rain_inch", "sensors");
            }
            else if (key == "dailyrainin")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Inch, "", 2, 2);
                hfs->addDBHook(_pathbase + "dailyrain_inch", "sensors");
            }
            else if (key == "weeklyrainin")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Inch, "", 2, 2);
                hfs->addDBHook(_pathbase + "weeklyrain_inch", "sensors");
            }
            else if (key == "monthlyrainin")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Inch, "", 2, 2);
                hfs->addDBHook(_pathbase + "monthlyrain_inch", "sensors");
            }
            else if (key == "solarradiation")
            {
                hfs->providesSensor(this, fkey, DT_Numeric, Wm2, "", 2, 3);
                hfs->addDBHook(_pathbase + "solarradiation", "sensors");
            }
            else if (key == "UV")
            {
                hfs->providesSensor(this, fkey, DT_Integer, Level);
                hfs->addDBHook(_pathbase + "UV", "sensors");
            }
        }
    }
    */

    /*
    hfs->providesSensor(this, _pathbase + "indoortemp_F", DT_Numeric, Farenheit, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "indoortemp_C", DT_Numeric, Celsius, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "temp_F", DT_Numeric, Farenheit, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "temp_C", DT_Numeric, Celsius, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "dewpt_F", DT_Numeric, Farenheit, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "dewpt_C", DT_Numeric, Celsius, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "windchill_C", DT_Numeric, Celsius, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "windspeed_MPH", DT_Numeric, Mph, "", 2, 3);
    hfs->providesSensor(this, _pathbase + "windspeed_KMH", DT_Numeric, Kmh, "", 2, 3);
    hfs->providesSensor(this, _pathbase + "windgust_MPH", DT_Numeric, Mph, "", 2, 3);
    hfs->providesSensor(this, _pathbase + "windgust_KMH", DT_Numeric, Kmh, "", 2, 3);

    hfs->providesSensor(this, _pathbase + "absbarom_InHg", DT_Numeric, InHg, "", 2, 4);
    hfs->providesSensor(this, _pathbase + "barom_InHg", DT_Numeric, InHg, "", 2, 4);
    hfs->providesSensor(this, _pathbase + "absbarom_HgMM", DT_Numeric, HgMM, "", 2, 4);
    hfs->providesSensor(this, _pathbase + "barom_HgMM", DT_Numeric, HgMM, "", 2, 4);
    hfs->providesSensor(this, _pathbase + "absbarom_HPa", DT_Numeric, hPa, "", 2, 4);
    hfs->providesSensor(this, _pathbase + "barom_HPa", DT_Numeric, hPa, "", 2, 4);

    hfs->providesSensor(this, _pathbase + "rain_inch", DT_Numeric, Inch, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "dailyrain_inch", DT_Numeric, Inch, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "weeklyrain_inch", DT_Numeric, Inch, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "monthlyrain_inch", DT_Numeric, Inch, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "rain_mm", DT_Numeric, Milimeter, "", 2, 2);
    hfs->providesSensor(this, _pathbase + "dailyrain_mm", DT_Numeric, Milimeter, "", 2, 3);
    hfs->providesSensor(this, _pathbase + "weeklyrain_mm", DT_Numeric, Milimeter, "", 2, 3);
    hfs->providesSensor(this, _pathbase + "monthlyrain_mm", DT_Numeric, Milimeter, "", 2, 3);

    hfs->providesSensor(this, _pathbase + "winddir", DT_Integer, Compass);
    hfs->providesSensor(this, _pathbase + "indoorhumidity", DT_Numeric, Percent, "", 1, 2);
    hfs->providesSensor(this, _pathbase + "humidity", DT_Numeric, Percent, "", 1, 2);
    hfs->providesSensor(this, _pathbase + "solarradiation", DT_Numeric, Wm2, "", 2, 3);
    hfs->providesSensor(this, _pathbase + "UV", DT_Integer, Level);
    hfs->providesSensor(this, _pathbase + "dateutc", DT_String, String);
    hfs->providesSensor(this, _pathbase + "softwaretype", DT_String, String);

    hfs->addDBHook(_pathbase + "indoortemp_F", "sensors");
    hfs->addDBHook(_pathbase + "indoortemp_C", "sensors");
    hfs->addDBHook(_pathbase + "temp_F", "sensors");
    hfs->addDBHook(_pathbase + "temp_C", "sensors");
    hfs->addDBHook(_pathbase + "dewpt_F", "sensors");
    hfs->addDBHook(_pathbase + "dewpt_C", "sensors");
    hfs->addDBHook(_pathbase + "windchill_F", "sensors");
    hfs->addDBHook(_pathbase + "windchill_C", "sensors");
    hfs->addDBHook(_pathbase + "windspeed_MPH", "sensors");
    hfs->addDBHook(_pathbase + "windspeed_KMH", "sensors");
    hfs->addDBHook(_pathbase + "windgust_MPH", "sensors");
    hfs->addDBHook(_pathbase + "windgust_KMH", "sensors");

    hfs->addDBHook(_pathbase + "absbarom_InHg", "sensors");
    hfs->addDBHook(_pathbase + "barom_InHg", "sensors");
    hfs->addDBHook(_pathbase + "absbarom_HgMM", "sensors");
    hfs->addDBHook(_pathbase + "barom_HgMM", "sensors");
    hfs->addDBHook(_pathbase + "absbarom_HPa", "sensors");
    hfs->addDBHook(_pathbase + "barom_HPa", "sensors");

    hfs->addDBHook(_pathbase + "rain_inch", "sensors");
    hfs->addDBHook(_pathbase + "dailyrain_inch", "sensors");
    hfs->addDBHook(_pathbase + "weeklyrain_inch", "sensors");
    hfs->addDBHook(_pathbase + "monthlyrain_inch", "sensors");
    hfs->addDBHook(_pathbase + "rain_mm", "sensors");
    hfs->addDBHook(_pathbase + "dailyrain_mm", "sensors");
    hfs->addDBHook(_pathbase + "weeklyrain_mm", "sensors");
    hfs->addDBHook(_pathbase + "monthlyrain_mm", "sensors");

    hfs->addDBHook(_pathbase + "winddir", "sensors");
    hfs->addDBHook(_pathbase + "indoorhumidity", "sensors");
    hfs->addDBHook(_pathbase + "humidity", "sensors");
    hfs->addDBHook(_pathbase + "solarradiation", "sensors");
    hfs->addDBHook(_pathbase + "UV", "sensors");
    */

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
    if (sidx == -1 || eidx==-1) // fragment arrived, head or tail of the string is missing
    {
        log(Info, "Fragment arrived, bail out");
        return;
    }

    if (qidx<sidx || qidx>eidx) // multiple HTTP request in one
    {
        log(Info, "Multiple GET in report");
        return;
    }

    // cut unneded header/tail parts
    s = s.mid(qidx+1, eidx-qidx-1);
    QStringList sl = s.split("&");      // only the part between the first ? and HTTP/1.0 is used
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

    if (!parsecnt)
    {
        parsecnt++;
        qDebug() << sl;
        provideSensors(sl);
    }

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
#if 1
                QString _ss = _pathbase + key;
                hfs->dataChangeRequest(this, "", _ss, val);

#else

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
                                hfs->dataChangeRequest(this, _sessionid, _pathbase + key + postfixs.at(j), val);
                                hfs->dataChangeRequest(this, _sessionid, _pathbase+key+postfixs.at(j+1), hround(convert(hunits.at(j),hunits.at(j+1),val.toDouble()),2));
                            }
                            else        // Imperial unit found
                            {
                                hfs->dataChangeRequest(this, _sessionid, _pathbase+key+postfixs.at(j), val);
                                hfs->dataChangeRequest(this, _sessionid, _pathbase+key+postfixs.at(j-1), hround(convert(hunits.at(j),hunits.at(j-1),val.toDouble()),2));
                            }
                        }
                        else    // Barometric values handled differently
                        {
                            double baseHPa = convert(InHg, hPa, val.toDouble());
                            hfs->dataChangeRequest(this, _sessionid, _pathbase+key+"_InHg", hround(convert(hPa, InHg, baseHPa),3));
                            hfs->dataChangeRequest(this, _sessionid, _pathbase+key+"_HPa",  hround(baseHPa,3));
                            hfs->dataChangeRequest(this, _sessionid, _pathbase+key+"_HgMM", hround(convert(hPa, HgMM, baseHPa),3));
                        }
                    }
                }
#endif
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

