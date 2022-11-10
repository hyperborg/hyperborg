#include "hudtimetable.h"

HUDTimeTable::HUDTimeTable(QQuickItem* parent) : HUDElement(parent)
{
    nam = new QNetworkAccessManager(this);
    connect(nam, &QNetworkAccessManager::finished, this, &HUDTimeTable::updateTimeTablereplyFinished);

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateTimeTable()));
    timer->setSingleShot(false);
    timer->start(60 * 1000);  // We do not trigger this ... let's spare the resource of public transport service's server
}

HUDTimeTable::~HUDTimeTable()
{}

void HUDTimeTable::paint(QPainter* painter)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);

    // general values
    int w = width();
    int h = height();
    double d_width = 600.0;     // design width and height
    double d_height = 300.0;

    double scalex = w / d_width;
    double scaley = h / d_height;
    painter->scale(scalex, scaley);

    int wh = w / 2;
    int hh = h / 2;

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, d_width - 2, d_height - 2, 5, 5);

    painter->setPen(QColor(245, 245, 245));

    QFont f;
    f.setPixelSize(16);
    f.setBold(true);
    painter->setFont(f);
    QFontMetrics fm(f);
    int th = fm.height();
    painter->drawText(8, th + 6, _stationName);
    int tiw = fm.horizontalAdvance("XX:XX");
    int sw = fm.horizontalAdvance("X");
    QList<int> rs;
    rs << 5;
    rs << rs.last() + tiw + 10;
    rs << rs.last() + tiw + 10;
    rs << rs.last() + sw*8 + 10;
    rs << rs.last() + sw * 30 + 10;

    // draw headers
    int yo = 2 * th + 16;
    painter->drawText(rs.at(0), yo, "Time");
    painter->drawText(rs.at(1), yo, "ACT");
    painter->drawText(rs.at(2), yo, "Num");
    painter->drawText(rs.at(3), yo, "Destination");
    painter->drawText(rs.at(4), yo, "Peron");

    painter->drawLine(5, yo + 7, w - 5, yo + 7);
    yo += 25;
    for (int i = 0; i < timetable_lst.count() && i < 10; ++i)
    {
        QStringList lst = timetable_lst.at(i).split(";");
        if (lst.count() == 7)
        {
            if (lst.at(1).isEmpty())
            {
                painter->setPen(QColor(245, 245, 245));
            }
            else
            {
                painter->setPen(QColor(Qt::red));
                if (!lst.at(6).isEmpty()) lst[5] = lst[6];
            }

            painter->drawText(rs.at(0), yo, lst.at(0));
            painter->drawText(rs.at(1), yo, lst.at(1));
            painter->drawText(rs.at(2), yo, lst.at(2));
            painter->drawText(rs.at(3), yo, lst.at(3));
            painter->drawText(rs.at(4), yo, lst.at(5));
            yo += th + 2;
        }
    }
}

void HUDTimeTable::loadConfiguration(QJsonObject& json)
{
}

void  HUDTimeTable::parseStationInfo(QString str)
{
    timetable_lst.clear();
    qDebug() << "parseStationInfo " ;
    if (str.mid(0,13)=="journeysObj =")
        str = str.mid(13);

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(str.toLocal8Bit(), &err);

    if (doc.isNull())
    {
        qDebug() << "NOT A VALID JSON DOCUMENT";
        return;
    }

    QJsonObject obj = doc.object();
    if (obj.isEmpty())
    {
        qDebug() << "JSON object is empty.";
        return;
    }

    if (obj.contains("journey") && obj["journey"].isArray())
    {
        QJsonArray arr = obj["journey"].toArray();
        for (int i=0;i<arr.count();i++)
        {
            QStringList tlst;
            if (arr.at(i).isObject())
            {
                QJsonObject unit = arr.at(i).toObject();
                QString scheduled_time = unit["ti"].toString();
                QString name = unit["pr"].toString();
                QString origin = unit["st"].toString();
                QString destination = unit["lastStop"].toString();
                QString peron = unit["tr"].toString();
                QString delayed_time;
                QString status;
                QString unit_rt = unit["rt"].toString();
                if (unit["rt"].isObject())
                {
                    QJsonObject rto = unit["rt"].toObject();
                    delayed_time=rto["dlt"].toString();
                    status = rto["status"].toString();
                }
                tlst << scheduled_time << delayed_time << name << origin << destination << peron << status;
            }
            if (tlst.count())
                timetable_lst << tlst.join(";");
        }
    }
    update();
}

void HUDTimeTable::saveConfiguration(QJsonObject& json)
{
}

// ================================= For HUDTable direct implementation

void HUDTimeTable::updateTimeTable()
{
    if (_stationId.isEmpty()) return;
    QDateTime dt;
    dt = QDateTime::currentDateTime();
    dt = dt.addMSecs(-1000 * 60 * 15);
    QUrl url("https://fahrplan.oebb.at/bin/stboard.exe/dn?L=vs_scotty.vs_liveticker&evaId="+_stationId+"&boardType=dep&time=" + dt.toString("hh:mm") + "&productsFilter=1011111111011&additionalTime=0&maxJourneys=50&outputMode=tickerDataOnly&start=yes&selectDate=today");

    QString cookie = "_pk_id.62.d415=36faea99a7c8bf47.1645585785.6.1650640857.1648725809.; oebbHistory=Location1%3DA%3D1%40O%3D" + _stationName + "%40X%3D16395057%40Y%3D47904675%40u%3D0%40U%3D81%40L%3D1130626%40%26; _pk_id.31.510b=e4509546712b4ab9.1650640945.1.1650641028.1650640945.";

    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Accept", "*/*");
    request.setRawHeader("Accept-Language", "hu,en-US;q=0.9,en;q=0.8,ja;q=0.7");
    request.setRawHeader("Connection", "keep-alive");
    request.setRawHeader("Cookie", QByteArray(cookie.toLatin1()));
    request.setRawHeader("DNT", "1");
    request.setRawHeader("Host", "fahrplan.oebb.at");
    request.setRawHeader("Referer", "https://fahrplan.oebb.at/bin/stboard.exe/dn?L=vs_scotty.vs_liveticker&evaId=1130626&boardType=dep&productsFilter=1011111111011&dirInput=&tickerID=dep&start=yes&eqstops=true&showJourneys=12&additionalTime=0");
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36");
    nam->get(request);
}

void HUDTimeTable::updateTimeTablereplyFinished(QNetworkReply* reply)
{
    if (!reply) return;

    cookies_variant = reply->header(QNetworkRequest::SetCookieHeader);
    if (cookies_variant.isValid())
    {
        cookies = cookies_variant.value<QList<QNetworkCookie>>();
    }

    QString readallstr = reply->readAll();
    parseStationInfo(readallstr);
}

