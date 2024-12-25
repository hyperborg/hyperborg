#include <ws3500.h>

WS3500_Device::WS3500_Device(QObject *parent) : HDevice(parent)
    ,server(nullptr)
{
    loadSensorInfos();
}

WS3500_Device::~WS3500_Device()
{
    shutdown();
}

void WS3500_Device::loadConfiguration(QString str)
{
    shutdown();
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &WS3500_Device::newConnection);
    if (!server->listen(QHostAddress::Any, 33336)) 
    {
        qCritical() << "Failed to start server:" << server->errorString();
    }
    else {
        qDebug() << "WS3500 init with HFS: " << hfs;
    }
}

void WS3500_Device::shutdown()
{
    if (server)
    {
        server->close();
        server->deleteLater();
        server =  nullptr;
    }
}

void WS3500_Device::loadSensorInfos()
{
    sensorinfos.clear();
    QList<SensorInfo> slst = {
        {"id",              DT_String},
        {"password",        DT_String},
        {"dateutc",         DT_String},
        {"realtime",        DT_Integer},
        {"rtfreq",          DT_Integer},
        {"softwaretype",    DT_String},
        {"action",          DT_String},
        {"indoorhumidity",  DT_Numeric, Percent},
        {"humidity",        DT_Numeric, Percent},
        {"indoortempf",     DT_Numeric, Farenheit},
        {"tempf",           DT_Numeric, Farenheit},
        {"dewptf",          DT_Numeric, Farenheit},
        {"windchillf",      DT_Numeric, Farenheit},
        {"indoortempc",     DT_Numeric, Celsius},
        {"tempc",           DT_Numeric, Celsius},
        {"dewptc",          DT_Numeric, Celsius},
        {"windchillc",      DT_Numeric, Celsius},
        {"windspeedmph",    DT_Numeric, Mph},
        {"windgustmph",     DT_Numeric, Mph},
        {"windspeedkmh",    DT_Numeric, Kmh},
        {"windgustkmh",     DT_Numeric, Kmh},
        {"winddir",         DT_Integer, Compass},
        {"absbaromin",      DT_Numeric, InHg},
        {"baromin",         DT_Numeric, InHg},
        {"rainin",          DT_Numeric, Inch},
        {"dailyrainin",     DT_Numeric, Inch},
        {"weeklyrainin",    DT_Numeric, Inch},
        {"monthlyrainin",   DT_Numeric, Inch},
        {"raincm",          DT_Numeric, Centimeter},
        {"dailyraincm",     DT_Numeric, Centimeter},
        {"weeklyraincm",    DT_Numeric, Centimeter},
        {"monthlyraincm",   DT_Numeric, Centimeter},
        {"solarradiation",  DT_Numeric, Wm2},
        {"uv",              DT_Integer, Level},
        {"dateutc",         DT_TimeStamp}
    };

    for (const auto& info : slst) {
        sensorinfos.insert(info.key, info);
    }
   
    for (auto it = sensorinfos.cbegin(); it != sensorinfos.cend(); ++it) 
    {
        qDebug() << it.value().key << " " << it.value().datatype << " " << it.value().unit;
    }
}

HActor *WS3500_Device::getActor(QString key)
{
    if (!sensorinfos.contains(key))
        return nullptr;

    Unit unit;
    int trc = 0;
    QString l3 = key.last(3);
    if      (l3         =="kmh") { unit=Kmh;        trc = 3; }
    else if (l3         =="mph") { unit=Mph;        trc = 3; }
    else if (key.last(2)=="mm")  { unit=Milimeter;  trc = 2; }
    else if (key.last(2)=="in")  { unit=Inch;       trc = 2; }
    else if (key.last(1)=="f")   { unit=Farenheit;  trc = 1; }
    else if (key.last(1)=="c" && l3!="utc")
                                 { unit=Celsius;    trc = 1; }

    QString basename = key;
    basename.chop(trc);
    if (actors.contains(basename))
        return actors[basename];

    HSensor *sensor = new HSensor(basename, key, sensorinfos.value(key),this);
    hfs->provides(sensor, "sensors.ws3500."+basename);
    
    return sensor;

}

void WS3500_Device::newConnection()
{
    if (!server) return;
    while (server->hasPendingConnections())
    {
        if (QTcpSocket *socket  = server->nextPendingConnection())
        {
            sockets.append(socket);
            QObject::connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
            QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
        }
    }
}

void WS3500_Device::stateChanged(QAbstractSocket::SocketState socketState)
{
    switch(socketState)
    {
        case QAbstractSocket::ClosingState:
        {
            if (QTcpSocket *sck=qobject_cast<QTcpSocket *>(sender()))
            {
                sockets.removeAll(sck);
                sck->deleteLater();
            }
        }
        default:
            break;
    }
}

void WS3500_Device::readyRead()
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

/* Note on accepting and parsing connection: The weatherstation does sends all of its data as a GET frame.
Here we do not want to create too much fuss about it, there is no need for full HTTP header parsing and so.
We look for what we expect. If that fits, we parse, if not we log that and discard. This way we can keep
this module small and simple.

Communication wise, we do not keep the TCP/IP connection open and expect to have a full header in a new
connection.
*/

// sample: "GET /wetterstation.php?ID=123&PASSWORD=123&indoortempf=77.7&tempf=76.6&dewptf=59.4&windchillf=76.6&indoorhumidity=51&humidity=55&windspeedmph=0.0&windgustmph=0.0&winddir=3&absbaromin=29.407&baromin=29.977&rainin=0.000&dailyrainin=0.000&weeklyrainin=0.000&monthlyrainin=0.000&solarradiation=0.00&UV=0&dateutc=2021-08-24%2019:28:54&softwaretype=EasyWeatherV1.5.9&action=updateraw&realtime=1&rtfreq=5 HTTP/1.0\r\nHost: 192.168.37.27\r\nAccept:*/*\r\nConnection: Close\r\n\r\n"

void WS3500_Device::parse(QString s)
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

    buffer.clear();
    for (const auto& param : sl) 
    {
        QString key, val;
        if (splitKeyAndVal(param, key, val))
        {
            buffer.insert(key.toLower(), val);
        }
    }

    if (!checkAccess(buffer.value("id"), buffer.value("password")))
    {
        buffer.clear();
        return;
    }

    for (const auto& param : sl)
    {
        QString key;
        QString val;
        if (splitKeyAndVal(param, key, val))
        {
            if (HSensor* sensor = dynamic_cast<HSensor*>(getActor(key)))
            {
                sensor->setProperty("rawvalue", val);
            }
        }
    }
}

bool WS3500_Device::checkAccess(QString id, QString cpasswd)
{
    if (id.isEmpty())       // WU expects this value to be provided
        return false;
    if (id==devid && cpasswd==passwd)
        return true;
    // At this moment we allow all ws access
    return true;
}

