#include <ws3500.h>

ws3500::ws3500(QObject *parent) :  parsecnt(0)
{
}

ws3500::~ws3500()
{
}

void ws3500::loadConfiguration(QString str)
{
    qDebug() << "WS3500 init with HFS: " << hfs;
    _pathbase = "sensors.ws3500.";

    loadSensorInfos();
    server = new QTcpServer(this);
    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    server->listen(QHostAddress::Any, 33336);
}


void ws3500::newConnection()
{
    if (!server) return;
    while (server->hasPendingConnections())
    {
        if (QTcpSocket *socket  = server->nextPendingConnection())
        {
            //QString all(socket->readAll());
            sockets.append(socket);
            QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
            qDebug() << "Currently there are " << sockets.count() << " sockets are registered";
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

void ws3500::loadSensorInfos()
{
    sensorinfos.clear();
    QList<SensorInfo> slst;

    slst << SensorInfo("id",               DT_String);
    slst << SensorInfo("password",         DT_String);
    slst << SensorInfo("indoorhumidity",   DT_Numeric, Percent);
    slst << SensorInfo("humidity",         DT_Numeric, Percent);

    slst << SensorInfo("indoortempf",      DT_Numeric, Farenheit);
    slst << SensorInfo("tempf",            DT_Numeric, Farenheit);
    slst << SensorInfo("dewptf",           DT_Numeric, Farenheit);
    slst << SensorInfo("windchillf",       DT_Numeric, Farenheit);
    slst << SensorInfo("windspeedmph",     DT_Numeric, Mph);
    slst << SensorInfo("windgustmph",      DT_Numeric, Mph);
    slst << SensorInfo("winddir",          DT_Integer, Compass);
    slst << SensorInfo("absbaromin",       DT_Numeric, InHg);
    slst << SensorInfo("baromin",          DT_Numeric, InHg);
    slst << SensorInfo("rainin",           DT_Numeric, Inch);
    slst << SensorInfo("dailyrainin",      DT_Numeric, Inch);
    slst << SensorInfo("weeklyrainin",     DT_Numeric, Inch);
    slst << SensorInfo("monthlyrainin",    DT_Numeric, Inch);
    slst << SensorInfo("solarradiation",   DT_Numeric, Wm2);
    slst << SensorInfo("uv",               DT_Integer, Level);
    slst << SensorInfo("dateutc",          DT_TimeStamp);
    slst << SensorInfo("softwaretype",     DT_String);
    slst << SensorInfo("action",           DT_String);
    slst << SensorInfo("realtime",         DT_Integer);
    slst << SensorInfo("rtfreq",           DT_Integer);

    for (int i = 0; i < slst.count(); i++)
        sensorinfos.insert(slst.at(i).key, slst.at(i));

    QHashIterator<QString, SensorInfo> it(sensorinfos);
    while (it.hasNext())
    {
        it.next();
        qDebug() << it.value().key << " " << it.value().datatype << " " << it.value().unit;
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

void ws3500::parse(QString s)
{
    qDebug() << s;
    int sidx = s.indexOf("GET ", 0, Qt::CaseInsensitive);
    int qidx = s.indexOf("?", 0, Qt::CaseSensitive);
    int eidx = s.indexOf(" HTTP/", 0, Qt::CaseInsensitive);
    if (sidx == -1 || eidx == -1) // fragment arrived, head or tail of the string is missing
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
    s = s.mid(qidx + 1, eidx - qidx - 1);
    QStringList sl = s.split("&");      // only the part between the first ? and HTTP/1.0 is used
    // prescanning for id & password, required for authentication and Entity existence
    // check

    QHash<QString, QString> inputs;

    QString key, val;
    for (int i = 0; i < inputs.count(); i++)
    {
        if (splitKeyAndVal(sl.at(i), key, val))
        {
            inputs.insert(key.toLower(), val);
        }
    }

    if (!checkAccess(inputs.value("id"), inputs.value("password")))
        return; // should validate source against some local auth database

    inputs.remove("id");
    inputs.remove("password");

    QHashIterator<QString, QString> it(inputs);
    while (it.hasNext())
    {
        it.next();
        HSensor* sensor = sensors.value(key, nullptr);
        if (sensorinfos.contains(key))
        {
            if (!sensor)
            {
                sensor = new HSensor(sensorinfos.value(key));
                sensors.insert(key, sensor);
                emit attachActor(sensor);
            }
            if (sensor)
            {
                sensor->setValue(val);
            }
        }
    }
}

bool ws3500::checkAccess(QString id, QString passwd)
{
    // At this moment we allow all ws access
    if (id.isEmpty()) return false;
    return true;
}

