#include <hue_device.h>

hue_device::hue_device(QObject *parent) : HDevice(parent), netman(nullptr)
{
}

hue_device::~hue_device()
{
}

void hue_device::init()
{
}

void hue_device::setup()
{
    netman = new QNetworkAccessManager(this);
    QObject::connect(netman, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleNetworkData(QNetworkReply*)));
    QObject::connect(netman,SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(handleSSLErrors(QNetworkReply*)));

    getAllLights();
    getConfiguration();
}

void hue_device::connectToRealDevice()
{
}

/* ------------ API CMD GENERATION ----------------------- */

// LIGHT API
void hue_device::getAllLights()
{
    proceed(GET, "lights", "", "");
}

void hue_device::getNewLights()
{
    proceed(GET, "lights/new", "", "");
}

void hue_device::getLightAttributesAndState(QString id)
{
    proceed(GET, QString("lights/%1").arg(id), "", "");
}

void hue_device::setLightAttribute(QString id)  // rename
{
    proceed(POST, QString("lights/%1").arg(id), "", "");
}

void hue_device::setLightState(QString id)
{
    proceed(POST, QString("lights/%1/state").arg(id), "", "");
    // requires body
}

void hue_device::deleteLight(QString id)
{
    proceed(DELETE, QString("lights/%1").arg(id), "", "");
}

// GROUPS API
void hue_device::getAllGroups()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::createGroup()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::getGroupAttributes()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::setGroupAttributes()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::setGroupState()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::deleteGroup()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}


// SCHEDULES API
void hue_device::getAllSchedules()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::createSchedule()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::getScheduleAttributes()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::setScheduleAttributes()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::deleteSchedule()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}


// SCENES API
void hue_device::getAllScenes()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::createScene()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::modifyScene()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::recallScene()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::deleteScene()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::getScene()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}


// SENSORS API
void hue_device::getAllSensors()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::createSensor()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::findNewSensors()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::getNewSensors()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::getSensor()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::updateSensor()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::deleteSensor()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::changeSensorState()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}


// RULES API
void hue_device::getAllRules()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::getRule()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::createRule()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::updateRule()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::deleteRule()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

// CONFIGURATION API
void hue_device::createUser()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::getConfiguration()
{
    proceed(GET, QString("config"), "", "");
}

void hue_device::modifyConfiguration()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::deleteUser()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::getFullState()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

// RESOURCELINKS API
void hue_device::getAllResourceLinks()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::getResourceLinks()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::createResourceLinks()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}

void hue_device::updateResourceLinks()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}


// CAPABILITIES API
void hue_device::getAllCapabilities()
{
    proceed(NOTIMPLEMENTED, QString("/%1").arg(""), "", "");
}





// ================================= COMMON EXECUTION CODE ===================================

void hue_device::handleNetworkData(QNetworkReply *reply)
{
    qDebug() << "NETWORK DATA FROM HUE ARRIVED: ";
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray response = reply->readAll();
        qDebug() << response;
    }
    else // handle error
    {
      qDebug() << reply->errorString();
    }
    reply->deleteLater();
}

void hue_device::handleSSLErrors(QNetworkReply *reply)
{
    Q_UNUSED(reply);
}

void hue_device::proceed(hue_device::Mode mode, QString cmd, QString body, QString parser)
{
    Q_UNUSED(parser);
    if (mode==NOTIMPLEMENTED)
    {
        qDebug() << "This function is not yet implemented!";
        return;
    }
    QString urlstr = QString("http://%1/api/%2/%3").arg(_host).arg(_username).arg(cmd);
    QUrl url = QUrl(urlstr);
    QNetworkRequest request(url);

    request.setRawHeader(QByteArray("User-Agent"), QByteArray("HYPERBORG HUE DEVICE DRIVER"));
    request.setRawHeader(QByteArray("X-Custom-User-Agent"), QByteArray("HYPERBORG HUE DEVICE DRIVER"));
    QByteArray bbody = body.toLocal8Bit();
    QByteArray bsize = QByteArray::number(bbody.size());

    if (bbody.size())
    {
        request.setRawHeader("Content-Type", "application/json");
        request.setRawHeader("Content-Length", bsize);
    }

    switch(mode)
    {
        case GET:
            netman->get(request);
            break;
        case POST:
            netman->post(request, bbody);
            break;
        case DELETE:
//            netman->deleteResource(request);
            break;
        case NOTIMPLEMENTED:
            break;
    }

}
